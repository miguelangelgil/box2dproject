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
    RigidBody rigidbody(Body_kind::DYNAMIC, Vector2f{ 0.f,0.f }, Vector2f{1.f,1.f}, 1.f, 1.f);
    CircleShape circle(100);
    Mesh mesh(circle);
    Entity my_entity(rigidbody,mesh);
    my_scene.add_entity(my_entity);


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

        // Swap the OpenGL buffers:

        window.display();
    } while (running);

    // Close the application:

    return (EXIT_SUCCESS);
}