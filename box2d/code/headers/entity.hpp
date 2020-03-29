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
    void update(RenderWindow& window);
    void draw(RenderWindow & window);
private:

    /** En Box2D las coordenadas Y crecen hacia arriba y en SFML crecen hacia abajo desde el borde superior.
     ** Esta función se encarga de convertir el sistema de coordenadas para que la escena no se vea invertida.
     **/
    Vector2f box2d_position_to_sfml_position(const b2Vec2& box2d_position, float window_height)
    {
        return Vector2f(box2d_position.x, window_height - box2d_position.y);
    }

};