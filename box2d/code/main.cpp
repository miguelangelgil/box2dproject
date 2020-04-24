
#include <box2d.h>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/rigidbody.hpp"
#include "headers/mesh.hpp"
#include "headers/scene.hpp"
#include "headers/entity.hpp"
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
    b2Vec2 ground1_vertex[10] =
    {
        {0,0},      //1
        {0,13},     //2
        {11,13},    //3
        {13,11},    //4
        {14,10},    //5
        {16,7},      //6
        {19,5},      //7
        {24,4},      //8
        {11,4},      //9
        {40,2}

    };
    RigidBody rigidground(my_scene,Body_kind::STATIC,Vector2f(0.f,0.f), ground1_vertex,200.f,0.3f, 10);
    

  /*  RigidBody rigidbodybox(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 4.f), Vector2f(4.f, 1.5f), 1.f, 0.3f);
    RigidBody rueda1(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 2.f), 1.5f, 1.f, 0.6f);
    RigidBody rueda2(my_scene, Body_kind::DYNAMIC, Vector2f(2.f, 2.f), 1.5f, 1.f, 0.6f);*/

   

    Mesh ground_mesh(window, Color::Red);
   /* Mesh box_mesh(window ,Color::Green);
    Mesh ruedas1_mesh(window, Color::Cyan);
    Mesh ruedas2_mesh(window, Color::Cyan);*/

   
    Entity my_ground(rigidground, ground_mesh);
  /*  Entity my_box(rigidbodybox, box_mesh);
    my_box.add_body(rueda1, ruedas1_mesh, my_scene, b2Vec2(-1.8f,-1.f), b2Vec2(0.f, 0.f));
    my_box.add_body(rueda2, ruedas2_mesh, my_scene, b2Vec2(1.8f, -1.f), b2Vec2(0.f, 0.f));*/

   
   /* my_scene.add_entity(my_box);*/
    my_scene.add_entity(my_ground);
  
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
        window.draw(sprite);
        my_scene.draw();
        window.display();

        //delta_time = (delta_time + timer.getElapsedTime().asSeconds()) * 0.5f;
        //my_scene.get_world().ClearForces();
        
    } while (running);

    // Close the application:

    return 0;
}