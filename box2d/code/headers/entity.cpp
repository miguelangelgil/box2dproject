#include "entity.hpp"

Entity::Entity(RigidBody& rigidbody, Mesh& mesh):
    my_rigidbody(&rigidbody),
    my_mesh(&mesh)
{

}

void Entity::update()
{
}

void Entity::draw()
{
}
