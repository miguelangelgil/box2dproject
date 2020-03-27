#pragma once
#include<iostream>
#include "rigidbody.hpp"
#include "mesh.hpp"

class RigidBody;
class Entity 
{
private:

    RigidBody* my_rigidbody;
    Mesh* my_mesh;

public:
    Entity(RigidBody & rigidbody, Mesh & mesh);
    void update();
    void draw();

};