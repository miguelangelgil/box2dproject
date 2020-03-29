#include "entity.hpp"
#include <SFML/Window.hpp>

Entity::Entity(RigidBody& rigidbody, Mesh& mesh):
    my_rigidbody(&rigidbody),
    my_mesh(&mesh)
{

}

Entity::~Entity()
{
    delete my_rigidbody;
    delete &my_mesh;
}

void Entity::update()
{
    my_mesh->get_shape().setPosition(Vector2f(my_rigidbody->get_body()->GetTransform().p.x, my_rigidbody->get_body()->GetTransform().p.y));
}

void Entity::draw(RenderWindow & window)
{
    window.draw(my_mesh->get_shape());
}
