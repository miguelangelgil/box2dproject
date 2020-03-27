#include "rigidbody.hpp"
#include "scene.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

RigidBody::RigidBody(Scene &scene,Body_kind my_body_kind, Vector2f position, Vector2f size, float density, float friction, float rotation)
{
    body_definition.type = b2BodyType(my_body_kind);
    body_definition.position.Set(position.x,position.y);
    my_body = scene.get_world()->CreateBody(&body_definition);
}
