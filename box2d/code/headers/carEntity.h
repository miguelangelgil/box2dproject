#pragma once
#include "entity.hpp"
#include "SFML/Window.hpp"
class CarEntity : public Entity 
{
private :
    float current_speed;
    float speed;
    float speed_up;
    float speed_trunk;
public:
    /**
    Constructor de clase
    recive: 
    velocidad del motor
    aceleracion
    velocidad del remolque
    un rigidbody inicial
    mesh inicial
    */
    CarEntity(float speed, float speed_up,float speed_trunk, RigidBody& rigidBody, Mesh& mesh);
    /**
    Gestiona los inputs que controlan el coche
    */
    void update(float delta_Time);
};
