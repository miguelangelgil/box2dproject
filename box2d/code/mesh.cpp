#include "headers/mesh.hpp"
#include <cmath>
#include <box2d.h>

Mesh::Mesh(RenderWindow & window,Color color):
    window(&window),
    color(color),
    relative_position(0.0f,0.0f)
{
}

void Mesh::set_shape_circle(b2Vec2 center, b2Transform body_transform, float radius)
{
    circle_shape.setPosition(box2d_position_to_sfml_position(b2Mul(body_transform, center), (float)window->getSize().y) - Vector2f(radius, radius));
    circle_shape.setFillColor(color);
    circle_shape.setRadius(radius);
    type = TypeShape::CIRCLE;
}

void Mesh::set_shape_convex(b2Transform body_transform, vector<b2Vec2> vertex)
{
    convex_shape.setPointCount(vertex.size());
    convex_shape.setFillColor(color);
    this->vertex = vertex;

    for (int index = 0; index < vertex.size(); index++)
    {
        convex_shape.setPoint
        (
            index,
            box2d_position_to_sfml_position(b2Mul(body_transform, vertex[index]), (float)window->getSize().y)
            );
    }
    type = TypeShape::CONVEX;
    

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

void Mesh::update_mesh(b2Transform transform_body)
{
    switch (type)
    {
    case CONVEX:
        for(size_t index = 0;index < vertex.size();index++)
        {
            convex_shape.setPoint(index,box2d_position_to_sfml_position(b2Mul(transform_body, vertex[index]), (float)window->getSize().y));
        }
        break;

    case CIRCLE:
        circle_shape.setPosition(box2d_position_to_sfml_position(transform_body.p, (float)window->getSize().y) - Vector2f(circle_shape.getRadius(), circle_shape.getRadius()));
        circle_shape.setRotation(transform_body.q.GetAngle());
        break;
    default:
        break;
    }
}

void Mesh::draw_mesh()
{
    switch (type)
    {
    case CONVEX:
        window->draw(convex_shape);
        break;
    case CIRCLE:
        window->draw(circle_shape);
        break;
    default:
        break;
    }
}
