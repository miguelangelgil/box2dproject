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
    b2BodyDef body_definition;
    b2Shape * my_shape;
    

public:
    RigidBody(
        Scene& scene, Body_kind my_body_kind, Vector2f position,
        float radius, float density, float friction, float rotation = 0.0f, int vertex = 0);

    RigidBody(
        Scene & scene ,Body_kind my_body_kind, Vector2f position,
        Vector2f size, float density,float friction, float rotation = 0.0f, int vertex = 0);

    ~RigidBody() = default;

    b2Body* get_body();
    b2Shape* get_shape();


};
