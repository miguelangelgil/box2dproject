#include "headers/entity.hpp"
#include <SFML/Window.hpp>

Entity::Entity(RigidBody& rigidbody, Mesh& mesh)
{
    if (rigidbody.get_fixture()->GetType() == b2Shape::e_circle) 
    {
        b2CircleShape* circle = dynamic_cast<b2CircleShape*>(rigidbody.get_fixture()->GetShape());
        mesh.set_shape_circle(circle->m_p, rigidbody.get_body()->GetTransform(),circle->m_radius);
    }
    else if (rigidbody.get_fixture()->GetType() == b2Shape::e_polygon) 
    {
        b2PolygonShape* box2d_polygon = dynamic_cast<b2PolygonShape*>(rigidbody.get_fixture()->GetShape());
        vector<b2Vec2>vertex;
        for (size_t index = 0; index < box2d_polygon->m_count; index++) 
        {
            vertex.push_back(box2d_polygon->m_vertices[index]);
        }
        mesh.set_shape_convex(rigidbody.get_body()->GetTransform() ,vertex);
    }
    else if (rigidbody.get_fixture()->GetType() == b2Shape::e_chain) 
    {
        b2ChainShape* box2d_chain = dynamic_cast<b2ChainShape*>(rigidbody.get_fixture()->GetShape());
        vector<b2Vec2>vertex;
        for (size_t index = 0; index < box2d_chain->m_count; index++) 
        {
            vertex.push_back(box2d_chain->m_vertices[index]);
        }
        mesh.set_chain(rigidbody.get_body()->GetTransform(), vertex);

    }
    my_mesh.push_back(&mesh);
    my_rigidbody.push_back(&rigidbody);
}

void Entity::update()
{
    
    for (size_t index = 0; index < my_rigidbody.size(); index++) 
    {
        if(my_rigidbody[index]->get_body()->GetType() != b2BodyType::b2_staticBody)
            my_mesh[index]->update_mesh(my_rigidbody[index]->get_body()->GetTransform());
    }
       
               
}

void Entity::draw()
{
    for (auto&& mesh : my_mesh) 
    {
        mesh->draw_mesh();
    }
}

Mesh* Entity::get_mesh(int index)
{
    if (my_mesh.size() > index)
        return my_mesh[index];
    return nullptr;
}

RigidBody* Entity::get_body(int index)
{
    if(my_rigidbody.size() > index)
        return my_rigidbody[index];
    return nullptr;
}

vector<RigidBody*> Entity::get_bodies()
{
    return my_rigidbody;
}

void Entity::add_body(RigidBody& rigidbody, Mesh& mesh, Scene & scene, b2Vec2 anchorA, b2Vec2 anchorB)
{
    if (rigidbody.get_fixture()->GetType() == b2Shape::e_circle)
    {
        b2CircleShape* circle = dynamic_cast<b2CircleShape*>(rigidbody.get_fixture()->GetShape());
        mesh.set_shape_circle(circle->m_p, rigidbody.get_body()->GetTransform(), circle->m_radius);
    }
    else if (rigidbody.get_fixture()->GetType() == b2Shape::e_polygon)
    {
        b2PolygonShape* box2d_polygon = dynamic_cast<b2PolygonShape*>(rigidbody.get_fixture()->GetShape());
        vector<b2Vec2>vertex;
        for (size_t index = 0; index < box2d_polygon->m_count; index++)
        {
            vertex.push_back(box2d_polygon->m_vertices[index]);
        }
        mesh.set_shape_convex(rigidbody.get_body()->GetTransform(), vertex);
    }
    my_mesh.push_back(&mesh);
    my_rigidbody.push_back(&rigidbody);
  
    b2Vec2 axis(0.f, 1.f);
    b2RevoluteJointDef jointDef;
    jointDef.Initialize(my_rigidbody.front()->get_body(), my_rigidbody.back()->get_body(), my_rigidbody.back()->get_body()->GetPosition());
    jointDef.localAnchorA = anchorA;
    jointDef.localAnchorB = anchorB;
   /* jointDef.stiffness = 0.f;
    jointDef.damping = 0.f;*/
    //jointDef.enableLimit = true;
   /* jointDef.lowerTranslation = 20.f;
    jointDef.upperTranslation = 120.f;*/
    jointDef.enableMotor = false;
    jointDef.motorSpeed = 10.f;
    jointDef.collideConnected = false;
    

    std::cout << "localanchorA: " << "x: " << jointDef.localAnchorA.x << " y: " << jointDef.localAnchorA.y << endl;
    std::cout << "localanchorB: " << "x: " << jointDef.localAnchorB.x << " y: " << jointDef.localAnchorB.y << endl;

    scene.get_world().CreateJoint(&jointDef);
   
}

