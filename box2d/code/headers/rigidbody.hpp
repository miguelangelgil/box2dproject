#pragma once
#include<iostream>
#include <box2d.h>
#include "values.hpp"
#include "scene.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
class Scene;
class RigidBody 
{
private:
    b2Body* my_body; 
    Vector2f relative_position;
    b2Fixture* my_fixture;
    RenderWindow* window;
    Scene* scene;

public:
    /**
    Constructor para crear un cuerpo redondo
    */
    RigidBody(
        Scene& scene, Body_kind my_body_kind, Vector2f position,
        float radius, float density, float friction, float rotation = 0.0f);

    /**
    Constructor para crear un rectangulo
    */
    RigidBody(
        Scene& scene ,Body_kind my_body_kind, Vector2f position,
        Vector2f size, float density,float friction, float rotation = 0.0f);

    /**
    Constructor para crear una cadena
    */
    RigidBody(
        Scene& scene, Body_kind my_body_kind, Vector2f position,
        b2Vec2 * vertex, float density, float friction, size_t vertex_count);

    /**
    Constructor para crear un poligono de maximo 8 vertices
    */
    RigidBody(
        Scene& scene, Body_kind my_body_kind, Vector2f position,
        b2Vec2* vertex, size_t vertex_count, float density, float friction);

    /**
     Constructor para crear un segmento
    */
    RigidBody(
        Scene& scene, RenderWindow& window,Body_kind my_body_kind, Vector2f position, float angle);
    /**
    Destructor de clase
    */
    ~RigidBody() = default;
    /**
    retorna la referencia del body de box2d
    */
    b2Body* get_body() { return my_body; }
    /**
    retorna la referencia de la fixture de box2d
    */
    b2Fixture* get_fixture() { return my_fixture; }

};
