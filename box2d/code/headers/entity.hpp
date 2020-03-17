#pragma once
#include<iostream>
#include "rigidbody.hpp"
#include "mesh.hpp"
class Entity 
{
    RigidBody* my_rigidbody;
    Mesh* my_mesh;
public:
    Entity();
    void update();
    void draw();

};