
#include <box2d.h>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/rigidbody.hpp"
#include "headers/mesh.hpp"
#include "headers/scene.hpp"
#include "headers/entity.hpp"
#include "headers/carEntity.h"
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
    
    //my_view.setCenter(400,300);
    Scene my_scene(b2Vec2(0.f,-9.8f));
    b2Vec2 ground1_vertex[] =
    {
        {0,0},      //1
        {0,13},     //2
        {11,13},    //3
        {13,11},    //4
        {14,10},    //5
        {16,7},      //6
        {19,5},      //7
        {24,4},      //8
        {30,3},      //9
        {40,3.5},
        {53.5,6.3},
        {53.5,0}

    };
    b2Vec2 ground2_vertex[] =
    {
        {75, 0},
        {75, 3},
        {121,5.4},
        {121,0}

    };
    b2Vec2 trunk_vertex[] = 
    {
        {0,0},
        {0,1},
        {0.3,1},
        {0.3,0.2},
        {3.7,0.2},
        {3.7,1},
        {4,1},
        {4,0}
    };
    RigidBody rigidground1(my_scene,Body_kind::STATIC,Vector2f(0.f,0.f), ground1_vertex,200.f,0.3f, 12);
    RigidBody rigidground2(my_scene,Body_kind::STATIC,Vector2f(0.f,0.f), ground2_vertex,200.f,0.3f, 4);
    
    

    RigidBody carBody(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 17.f), Vector2f(4.f, 1.5f), 2.f, 0.3f);
    RigidBody wheel1(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 15.f), 1.5f, 1.f, 0.6f);
    RigidBody wheel2(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 15.f), 1.5f, 1.f, 0.6f);
    RigidBody trunk(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 18.f), trunk_vertex, 8, 200.f, 0.3f);

   

    Mesh ground_mesh1(window, Color::Red);
    Mesh ground_mesh2(window, Color::Red);
    Mesh car_mesh(window ,Color::Green);
    Mesh wheel1_mesh(window, Color::Cyan);
    Mesh wheel2_mesh(window, Color::Cyan);
    Mesh trunk_mesh(window, Color::Blue);

   
    Entity my_ground1(rigidground1, ground_mesh1);
    Entity my_ground2(rigidground2, ground_mesh2);
    Entity my_trunk(trunk, trunk_mesh);
    CarEntity my_box(200.f,30.f,carBody, car_mesh);
    my_box.add_engine_body(wheel1, wheel1_mesh, my_scene, 0.f, b2Vec2(-1.8f,-1.f), b2Vec2(0.f, 0.f));
    my_box.add_engine_body(wheel2, wheel2_mesh, my_scene, 0.f, b2Vec2(1.8f, -1.f), b2Vec2(0.f, 0.f));
    //my_box.add_engine_body(trunk, trunk_mesh, my_scene, 0.f, b2Vec2(-4.f, 1.5), b2Vec2(0.f, 0.f));

   
    my_scene.add_entity(my_box);
    my_scene.add_entity(my_ground1);
    my_scene.add_entity(my_ground2);
    my_scene.add_entity(my_trunk);
  
    Clock timer;
    float delta_time = 0.010f;


    window.setVerticalSyncEnabled(true);

    // Run the main loop:

    bool running = true;

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