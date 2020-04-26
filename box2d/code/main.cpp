
#include <box2d.h>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/rigidbody.hpp"
#include "headers/mesh.hpp"
#include "headers/scene.hpp"
#include "headers/entity.hpp"
#include "headers/carEntity.hpp"
#include <iostream>
#include <box2d.h>

using namespace std;
using namespace sf;

static const size_t window_width = 800;
static const size_t window_height = 600;

int main() 
{
    // Create the window and the view that will be shown within the window:
    RenderWindow window(VideoMode(1800, 600), "Animation Box2D (MAGMA)", Style::Titlebar | Style::Close, ContextSettings(32));
   
    Texture texture;
    Sprite sprite;
    texture.loadFromFile("../../assets/worldbox2d.PNG");
    sprite.setTexture(texture, true);
   
    sprite.scale(Vector2f(0.2, 0.2));
    sprite.setPosition(0, 600 - texture.getSize().y * sprite.getScale().y);
    float ar = texture.getSize().x  / texture.getSize().y ;
    float xp = (sprite.getPosition().x);
    float yp = (sprite.getPosition().y);
    float xs = texture.getSize().x *sprite.getScale().x;
    float ys = texture.getSize().y * sprite.getScale().y;
    View my_view(FloatRect(xp,yp,xs,ys));
    window.setView(my_view);
    
    Scene my_scene(b2Vec2(0.f,-9.8f));
    /**
    Vertices de la primera cadena que constitulle el suelo
    */
    b2Vec2 ground1_vertex[] =
    {
        {0,0},      
        {0,13},     
        {11,13},    
        {13,11},    
        {14,10},    
        {16,7},      
        {19,5},      
        {24,4},      
        {30,3},      
        {40,3.5},
        {53.5,6.3},
        {53.5,0}

    };
    /**
    Vertices que constitullen la segunda parte del suelo
    */
    b2Vec2 ground2_vertex[] =
    {
        {75, 0},
        {75, 3},
        {121,5.4},
        {121,0}

    };
    /**
    Se crea el suelo de la escena
    */
    RigidBody rigidground1(my_scene,Body_kind::STATIC,Vector2f(0.f,0.f), ground1_vertex,200.f,1.f, 12);
    RigidBody rigidground2(my_scene,Body_kind::STATIC,Vector2f(0.f,0.f), ground2_vertex,200.f,1.f, 4);

    /**
    Se crea el cuerpo del coche y sus partes
    */
    RigidBody carBody(my_scene, Body_kind::DYNAMIC, Vector2f(3.f, 17.f), Vector2f(4.f, 1.5f), 10.f, 0.3f);
    RigidBody wheel1(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 15.f), 1.5f, 1.f, 1.f);
    RigidBody wheel2(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 15.f), 1.5f, 1.f, 1.f);
    RigidBody trunk1(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 18.f), Vector2f(4.f, 0.3f), 1.f, 0.3f);
    RigidBody trunk2(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 18.f), Vector2f(0.3f, 2.f), 1.f, 0.3f);
    RigidBody trunk3(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 18.f), Vector2f(0.3f, 2.f), 1.f, 0.3f);

   
    /**
    Se crean los meshes del suelo
    */
    Mesh ground_mesh1(window, Color::Red);
    Mesh ground_mesh2(window, Color::Red);

    /**
    Se crean los meshes de las partes del coche
    */
    Mesh car_mesh(window ,Color::Green);
    Mesh wheel1_mesh(window, Color::Cyan);
    Mesh wheel2_mesh(window, Color::Cyan);
    Mesh trunk1_mesh(window, Color::Blue);
    Mesh trunk2_mesh(window, Color::Blue);
    Mesh trunk3_mesh(window, Color::Blue);

    /**
    Se crea la entidad del suelo
    */
    Entity my_ground1(rigidground1, ground_mesh1);
    Entity my_ground2(rigidground2, ground_mesh2);
    
    /**
    Se crea la entidad del maletero y se le añaden las 3 paredes que constitullen el recipiente
    */
    Entity my_trunk(trunk1, trunk1_mesh);
    my_trunk.add_fixed_body(trunk2, trunk2_mesh, my_scene, *my_trunk.get_body(0), b2Vec2(-4, 1), b2Vec2(0, -1));
    my_trunk.add_fixed_body(trunk3, trunk3_mesh, my_scene, *my_trunk.get_body(0), b2Vec2(4, 1), b2Vec2(0, -1));
    /**
    Se crea la entidad del coche y se le añaden las 2 ruedas y el maletero
    */
    CarEntity my_box(200.f,30.f,100,carBody, car_mesh);
    my_box.add_engine_body(wheel1, wheel1_mesh, my_scene, 0.f, b2Vec2(-3.f,-1.f), b2Vec2(0.f, 0.f));
    my_box.add_engine_body(wheel2, wheel2_mesh, my_scene, 0.f, b2Vec2(3.f, -1.f), b2Vec2(0.f, 0.f));
    my_box.add_engine_body(trunk1, trunk1_mesh, my_scene, 0.f, b2Vec2(-3.f, 1.f), b2Vec2(-3.f, -1.f));

    /**
    Se añaden todas la entidades a la escena
    */
    my_scene.add_entity(my_box);
    my_scene.add_entity(my_ground1);
    my_scene.add_entity(my_ground2);
    my_scene.add_entity(my_trunk);
    

  
    Clock timer;
    float delta_time = 0.010f;


    window.setVerticalSyncEnabled(true);

    // Run the main loop:

    bool running = true;
    /**Bucle principal de juego*/
    do
    {
        // Attend the window events:

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                running = false;
            }
        }

        
        my_scene.get_world().Step(delta_time, 8, 4);
        window.clear();
        my_scene.update();
        my_box.update(delta_time);
        window.draw(sprite);
        my_scene.draw();
        window.display();

        //delta_time = (delta_time + timer.getElapsedTime().asSeconds()) * 0.5f;
        //my_scene.get_world().ClearForces();
        
    } while (running);

    // Close the application:

    return 0;
}