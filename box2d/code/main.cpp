
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
    RenderWindow window(VideoMode(800, 600), "Animation Box2D (MAGMA)", Style::Titlebar | Style::Close, ContextSettings(32));
    View my_view(FloatRect(-260, -30, 800, 600));
    my_view.zoom(0.1f);
    window.setView(my_view);
    
    //my_view.setCenter(400,300);
    Scene my_scene(b2Vec2(0.f,-9.8f));

    RigidBody rigidground(my_scene,Body_kind::STATIC,Vector2f(120.f,300.f), Vector2f(20.f,5.f),200.f,0.3f);

    RigidBody rigidbodybox(my_scene,Body_kind::DYNAMIC,Vector2f(110.f,304.f), Vector2f(4.f,1.5f),1.f,0.3f);
    RigidBody rueda1(my_scene, Body_kind::DYNAMIC, Vector2f(110.f, 302.f), 1.5f, 1.f, 0.6f);
    RigidBody rueda2(my_scene, Body_kind::DYNAMIC, Vector2f(110.f, 302.f), 1.5f, 1.f, 0.6f);

   

    Mesh ground_mesh(window, Color::Red);
    Mesh box_mesh(window ,Color::Green);
    Mesh ruedas1_mesh(window, Color::Cyan);
    Mesh ruedas2_mesh(window, Color::Cyan);

   
    Entity my_ground(rigidground, ground_mesh);
    Entity my_box(rigidbodybox, box_mesh);
    my_box.add_body(rueda1, ruedas1_mesh, my_scene, b2Vec2(-1.8f,-1.f), b2Vec2(0.f, 0.f));
    my_box.add_body(rueda2, ruedas2_mesh, my_scene, b2Vec2(1.8f, -1.f), b2Vec2(0.f, 0.f));

   
    my_scene.add_entity(my_box);
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
        my_scene.draw();
        window.display();

        //delta_time = (delta_time + timer.getElapsedTime().asSeconds()) * 0.5f;
        //my_scene.get_world().ClearForces();
        
    } while (running);

    // Close the application:

    return 0;
}