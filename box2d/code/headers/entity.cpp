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

void Entity::update(RenderWindow& window)
{

    my_mesh->get_shape().setPosition(box2d_position_to_sfml_position(b2Mul(my_rigidbody->get_body()->GetTransform(),
        my_rigidbody->get_body()->GetPosition()),float(window.getSize().y)) - Vector2f(1.f,1.f));
}

void Entity::draw(RenderWindow & window)
{
    window.draw(my_mesh->get_shape());
}
