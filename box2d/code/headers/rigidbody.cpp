#include "rigidbody.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;

RigidBody::RigidBody(Body_kind my_body_kind, Vector2f position, Vector2f size, float density, float friction, float rotation)
{
    my_body
    my_body.SetType(b2BodyType(my_body_kind));
    my_body.SetTransform(b2Vec2(position.x, position.y), rotation);
}
