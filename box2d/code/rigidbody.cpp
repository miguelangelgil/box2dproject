#include "headers/rigidbody.hpp"
#include "headers/scene.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

RigidBody::RigidBody(Scene &scene,Body_kind my_body_kind, Vector2f position, float radius,
    float density, float friction, float rotation):
    scene(&scene)
{
    b2BodyDef body_definition;
    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x,position.y);
    my_body = scene.get_world().CreateBody(&body_definition);

    b2CircleShape shape;
    shape.m_radius = radius;
    b2FixtureDef body_fixture;
    body_fixture.shape = &shape;
    body_fixture.density = density;
    body_fixture.restitution = 0.50f;
    body_fixture.friction = friction;

    my_fixture = my_body->CreateFixture(&body_fixture);
}

RigidBody::RigidBody(Scene& scene, Body_kind my_body_kind, Vector2f position, Vector2f size,
    float density, float friction, float rotation):
    scene(&scene)
{
    b2BodyDef body_definition;
    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x, position.y);
    my_body = scene.get_world().CreateBody(&body_definition);

    b2PolygonShape shape;
    shape.SetAsBox(size.x,size.y);
    b2FixtureDef body_fixture;
    body_fixture.shape = &shape;
    body_fixture.density = density;
    body_fixture.restitution = 0.50f;
    body_fixture.friction = friction;

    my_fixture = my_body->CreateFixture(&body_fixture);
}

RigidBody::RigidBody(Scene& scene, Body_kind my_body_kind, Vector2f position,b2Vec2 * vertex, float density, float friction, size_t vertex_count):
    scene(&scene)
{
    b2BodyDef body_definition;
    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x, position.y);
    my_body = scene.get_world().CreateBody(&body_definition);

    b2ChainShape shape;
    shape.CreateChain(vertex, vertex_count);
    b2FixtureDef body_fixture;
    body_fixture.shape = &shape;
    body_fixture.density = density;
    body_fixture.restitution = 0.50f;
    body_fixture.friction = friction;

    my_fixture = my_body->CreateFixture(&body_fixture);

}

RigidBody::RigidBody(Scene& scene, Body_kind my_body_kind, Vector2f position, b2Vec2* vertex, size_t vertex_count, float density, float friction):
    scene(&scene)
{
    b2BodyDef body_definition;
    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x, position.y);
    my_body = scene.get_world().CreateBody(&body_definition);

    b2PolygonShape shape;
    shape.Set(vertex, vertex_count);
    b2FixtureDef body_fixture;
    body_fixture.shape = &shape;
    body_fixture.density = density;
    body_fixture.restitution = 0.50f;
    body_fixture.friction = friction;

    my_fixture = my_body->CreateFixture(&body_fixture);
}

RigidBody::RigidBody(Scene& scene, RenderWindow& window, Body_kind my_body_kind, Vector2f position, float angle):
    scene(&scene    )
{
    b2BodyDef body_definition;

    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x,position.y);                                       // Posici�n inicial absoluta
    body_definition.angle = angle;

    my_body = scene.get_world().CreateBody(&body_definition);

    // Se a�ande una fixture al body:

    b2EdgeShape body_shape;

    body_shape.Set(b2Vec2(0.f, 0.f), b2Vec2(float(window.getSize().x), 0.f));                    // Coordenadas locales respecto al centro del body

    b2FixtureDef body_fixture;

    body_fixture.shape = &body_shape;

    my_fixture = my_body->CreateFixture(&body_fixture);
}


