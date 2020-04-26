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
    /**
    Constructor de clase
    */
    Entity(RigidBody & rigidbody, Mesh & mesh);
    /**
    actualiza la vista de sfml
    */
    void update();
    /**
    pinta por ventana las formas de sfml
    */
    void draw();
    /**
    retorna la referencia de la clase mesh que se le indique con un indice
    */
    Mesh* get_mesh(int index);
    /**
    retorna la referencia a la clase rigidbody que se le indique con un indice
    */
    RigidBody* get_body(int index);
    /**
    retorna un vector de todos lor rigidbody que contiene la entidad
    */
    vector<RigidBody*> get_bodies();
    /**
    Junta dos cuerpos mediante una revolute joint
    */
    void add_engine_body(RigidBody & rigidbody, Mesh & mesh, Scene & scene,float speed, b2Vec2 anchorA, b2Vec2 anchorB);
    /**
    Junta los cuerpos mediante una weld
    */
    void add_fixed_body(RigidBody & rigidbody, Mesh & mesh, Scene & scene, RigidBody& bodyA  ,b2Vec2 anchorA, b2Vec2 anchorB);

};