#include "mesh.hpp"


Mesh::Mesh(Shape & shape):
    my_shape(&shape)
{
}

Mesh::~Mesh()
{
    delete &my_shape;
    delete &relative_position;
}

void Mesh::set_relative_position(Vector2f position)
{
    relative_position = position;
    my_shape->setPosition(relative_position);
}

Vector2f Mesh::get_relative_position()
{
    return relative_position;
}

void Mesh::set_color(const Color& color)
{
    my_shape->setFillColor(color);
}

Shape& Mesh::get_shape()
{
    return *my_shape;
}
