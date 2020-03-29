#pragma once
#include<iostream>
#include "rigidbody.hpp"
#include "mesh.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class RigidBody;
class Entity 
{
private:

    RigidBody* my_rigidbody;
    Mesh* my_mesh;

public:
    Entity(RigidBody & rigidbody, Mesh & mesh);
    ~Entity();
    void update();
    void draw(RenderWindow & window);

};