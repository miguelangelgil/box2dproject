
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "headers/rigidbody.hpp"
#include "headers/mesh.hpp"
#include "headers/scene.hpp"
#include "headers/entity.hpp"
#include <iostream>

using namespace std;
using namespace sf;

static const size_t window_width = 800;
static const size_t window_height = 600;

int main() 
{
    // Create the window and the view that will be shown within the window:
    RenderWindow window(VideoMode(800, 600), "Animation Box2D (MAGMA)", Style::Titlebar | Style::Close, ContextSettings(32));
    Scene my_scene;

    RigidBody rigidbodycircle(my_scene,Body_kind::DYNAMIC, Vector2f{ 100.f,200.f }, 10.f, 0.1f, 1.f);
    RigidBody rigidbodyground(my_scene, window, Body_kind::STATIC,Vector2f(0.f,20.f), 0.0f);
    RigidBody rigidbodybox(my_scene,Body_kind::DYNAMIC,Vector2f(120.f,600.f), Vector2f(50.f,50.f),0.1f,1.f);

 /*   CircleShape circle(10);
    RectangleShape rectangle(Vector2f(450.f,5.f));
    RectangleShape box(Vector2f(50.f, 50.f));

    rectangle.setFillColor(Color::Red);
    circle.setFillColor(Color::Blue);
    box.setFillColor(Color::Green);*/

    Mesh mesh(Color::Blue);
    Mesh ground_mesh(Color::Red);
    Mesh box_mesh(Color::Green);

    Entity my_entity(rigidbodycircle,mesh);
    Entity my_ground(rigidbodyground, ground_mesh);
    Entity my_box(rigidbodybox, box_mesh);

    my_scene.add_entity(my_entity);
    my_scene.add_entity(my_ground);
    my_scene.add_entity(my_box);

    my_scene.set_positions(window);

    Clock timer;
    float delta_time = 0.017f;;


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

        // Swap the OpenGL buffers
       // my_scene.update(window);
        my_scene.get_world()->Step(delta_time, 8, 4);
        my_scene.update(window);

        window.display();

        delta_time = (delta_time + timer.getElapsedTime().asSeconds()) * 0.5f;
        window.clear();
    } while (running);

    // Close the application:

    return (EXIT_SUCCESS);
}