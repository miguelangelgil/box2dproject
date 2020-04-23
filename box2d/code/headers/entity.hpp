#pragma once
#include<iostream>
#include <vector>
#include "rigidbody.hpp"
#include "mesh.hpp"
#include "scene.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
class Scene;
class RigidBody;
class Mesh;
class Entity 
{
private:

    vector <RigidBody*>        my_rigidbody;
    vector <Mesh*>             my_mesh;
public:
    Entity(RigidBody & rigidbody, Mesh & mesh);
    void update();
    void draw();
    RigidBody* get_body(int index);
    vector<RigidBody*> get_bodies();
    void add_body(RigidBody & rigidbody, Mesh & mesh, Scene & scene, b2Vec2 anchorA, b2Vec2 anchorB);
    void add_body(RigidBody & rigidbody, Mesh & mesh, Scene & scene);

};