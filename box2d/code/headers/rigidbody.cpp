#include "rigidbody.hpp"

RigidBody::RigidBody(body_kind my_body_kind, position_2d position, size_2d size, float density, float friction, float rotation)
{
    my_body->SetType(b2BodyType(my_body_kind));
    my_body->SetTransform(b2Vec2(position.x, position.y), rotation);
  
    
}
