#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "values.hpp"

using namespace sf;
class Mesh
{
private:
    Color color;
    Vector2f relative_position;
public:
    Mesh(Color color);
    void set_relative_position(Vector2f position);
    Vector2f get_relative_position();
    void set_color(const Color& color);
    Color get_color();

};
