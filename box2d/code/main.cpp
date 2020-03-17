#include <SFML/Window.hpp>
#include <iostream>

using namespace std;
using namespace sf;

static const size_t window_width = 800;
static const size_t window_height = 600;

int main() 
{
    // Create the window and the view that will be shown within the window:

    Window window(VideoMode(window_width, window_height), "Image Loader", Style::Titlebar | Style::Close, ContextSettings(32));

    // Initialization:

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