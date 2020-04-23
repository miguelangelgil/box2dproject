#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "values.hpp"
#include <box2d.h>

using namespace sf;
using namespace std;
class Mesh
{
private:
    Color color;
    Vector2f relative_position;
    ConvexShape convex_shape;
    CircleShape circle_shape;
    RenderWindow* window;
    TypeShape type;
    vector<b2Vec2> vertex;

public:
    Mesh(RenderWindow& window ,Color color);
    void set_shape_circle(b2Vec2 center,b2Transform body_transform, float radius);
    void set_shape_convex(b2Transform body_transform, vector<b2Vec2> vertex);
    void set_relative_position(Vector2f position);
    Vector2f get_relative_position();
    void set_color(const Color& color);
    Color get_color();
    void update_mesh(b2Transform transform_body);
    void draw_mesh();

};
