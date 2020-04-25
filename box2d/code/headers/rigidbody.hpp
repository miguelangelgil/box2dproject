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
    RigidBody(
        Scene& scene, Body_kind my_body_kind, Vector2f position,
        float radius, float density, float friction, float rotation = 0.0f);

    RigidBody(
        Scene& scene ,Body_kind my_body_kind, Vector2f position,
        Vector2f size, float density,float friction, float rotation = 0.0f);

    RigidBody(
        Scene& scene, Body_kind my_body_kind, Vector2f position,
        b2Vec2 * vertex, float density, float friction, size_t vertex_count);
    RigidBody(
        Scene& scene, Body_kind my_body_kind, Vector2f position,
        b2Vec2* vertex, size_t vertex_count, float density, float friction);
    RigidBody(
        Scene& scene, RenderWindow& window,Body_kind my_body_kind, Vector2f position, float angle);

    ~RigidBody() = default;

    b2Body* get_body() { return my_body; }
    b2Fixture* get_fixture() { return my_fixture; }

};
