#include "entity.hpp"
#include <SFML/Window.hpp>

Entity::Entity(RigidBody& rigidbody, Mesh& mesh):
    my_rigidbody(&rigidbody),
    my_mesh(&mesh)
{

}

void Entity::update(RenderWindow& window)
{

    my_mesh->get_shape().setPosition(box2d_position_to_sfml_position(b2Mul(my_rigidbody->get_body()->GetTransform(),
        my_rigidbody->get_body()->GetPosition()),float(window.getSize().y)) - Vector2f(my_rigidbody->get_shape()->m_radius, my_rigidbody->get_shape()->m_radius));
}

void Entity::draw(RenderWindow & window)
{
    window.draw(my_mesh->get_shape());
}

RigidBody* Entity::get_body()
{
    return my_rigidbody;
}
