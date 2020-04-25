#pragma once
#include "entity.hpp"
#include "SFML/Window.hpp"
class CarEntity : public Entity 
{
private :
    float current_speed;
    float speed;
    float speed_up;
public:
    CarEntity(float speed, float speed_up, RigidBody& rigidBody, Mesh& mesh);
    void update(float delta_Time);
};
