#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "values.hpp"

using namespace sf;
class Mesh
{
private:
    std::shared_ptr<sf::Shape> my_shape;
    Vector2f relative_position;

public:
    Mesh(Shape & shape);
    void set_relative_position(Vector2f position);
    Vector2f get_relative_position();
    void set_color(const Color& color);
    Shape& get_shape();

};
