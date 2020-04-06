#include "mesh.hpp"


Mesh::Mesh(Color color):
    color(color),
    relative_position(0.0f,0.0f)
{
}

void Mesh::set_relative_position(Vector2f position)
{
    relative_position = position;
}

Vector2f Mesh::get_relative_position()
{
    return relative_position;
}

void Mesh::set_color(const Color& color)
{
    this->color = color;
}

Color Mesh::get_color()
{
    return color;
}
