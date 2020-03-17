#include "rigidbody.hpp"

RigidBody::RigidBody(body_kind my_body_kind, position_2d position, size_2d size, float density, float friction)
{
    my_body->SetType(b2BodyType(my_body_kind));
    my_body->SetTransform(b2Transform(b2Vec2(position.x, position.y), b2Rot(0.0f)), 0.0f);
}
