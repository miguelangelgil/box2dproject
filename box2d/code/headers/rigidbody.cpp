#include "rigidbody.hpp"
#include "scene.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

RigidBody::RigidBody(Scene &scene,Body_kind my_body_kind, Vector2f position, float radius,
    float density, float friction, float rotation, int vertex)
{
    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x,position.y);
    my_body = scene.get_world()->CreateBody(&body_definition);

    b2CircleShape shape;
    shape.m_radius = radius;
    my_shape = &shape;
    b2FixtureDef body_fixture;
    body_fixture.shape = my_shape;
    body_fixture.density = density;
    body_fixture.restitution = 0.f;
    body_fixture.friction = friction;

    my_body->CreateFixture(&body_fixture);
}

RigidBody::RigidBody(Scene& scene, Body_kind my_body_kind, Vector2f position, Vector2f size,
    float density, float friction, float rotation, int vertex)
{
    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x, position.y);
    my_body = scene.get_world()->CreateBody(&body_definition);

    b2PolygonShape shape;
    my_shape = &shape;
    shape.SetAsBox(size.x,size.y);
    b2FixtureDef body_fixture;
    body_fixture.shape = my_shape;
    body_fixture.density = density;
    body_fixture.restitution = 0.f;
    body_fixture.friction = friction;

    my_body->CreateFixture(&body_fixture);
}

b2Body* RigidBody::get_body()
{
    return my_body;
}

b2Shape* RigidBody::get_shape()
{
    return my_shape;
}

