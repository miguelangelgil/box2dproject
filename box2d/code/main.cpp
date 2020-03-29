#include <memory>
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
    RigidBody rigidbody(my_scene,Body_kind::DYNAMIC, Vector2f{ 200.f,200.f }, Vector2f{10.f,10.f}, 1.f, 1.f);
    CircleShape circle(100);
    circle.setFillColor(Color::Blue);
    Mesh mesh(circle);
    Entity my_entity(rigidbody,mesh);
    my_scene.add_entity(my_entity);

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
        my_scene.draw(window);

        window.display();

        delta_time = (delta_time + timer.getElapsedTime().asSeconds()) * 0.5f;
        window.clear();
    } while (running);

    // Close the application:

    return (EXIT_SUCCESS);
}