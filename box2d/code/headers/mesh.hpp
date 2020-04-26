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
    Vertex *line;
    size_t vertex_count;
    Vertex max_vertex[100];
    RenderWindow* window;
    TypeShape type;
    vector<b2Vec2> vertex;

public:
    /**
    Constructor de clase
    */
    Mesh(RenderWindow& window ,Color color);
    /**
    Crea un circulo
    */
    void set_shape_circle(b2Vec2 center,b2Transform body_transform, float radius);
    /**
    Crea una figura geometrica de maximo 8 vertices
    */
    void set_shape_convex(b2Transform body_transform, vector<b2Vec2> vertex);
    /**
    Crea una cadena de nodos infinitos
    */
    void set_chain(b2Transform body_transform, vector<b2Vec2> vertex);
    /**
    Modifica la posicion relativa
    */
    void set_relative_position(Vector2f position);
    /**
    Retorna la posicion relativa
    */
    Vector2f get_relative_position();
    /**
    Asigna un color a la figura
    */
    void set_color(const Color& color);
    /**
    Retorna el color de la figura
    */
    Color get_color();
    /**
    Actualiza la posicion de la forma respecto a una posicion, la posicion de un cuerpo
    */
    void update_mesh(b2Transform transform_body);
    /**
    dibuja por pantalla las formas
    */
    void draw_mesh();

};
