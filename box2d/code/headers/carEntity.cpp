#include "carEntity.h"

CarEntity::CarEntity(float speed, float speed_up, float speed_trunk, RigidBody& rigidBody, Mesh& mesh) : Entity(rigidBody, mesh),
    speed(speed),
    speed_up(speed_up),
    speed_trunk(speed_trunk),
    current_speed(0.f)

{
}

void CarEntity::update(float delta_Time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {
        if (abs(current_speed) < abs(speed)) 
        {
            current_speed += speed_up * delta_Time;
        }
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[1]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(current_speed);
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[2]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(current_speed);
        
    } else 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (abs(current_speed) < abs(speed))
        {
            current_speed -= speed_up * delta_Time;
        }
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[1]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(current_speed);
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[2]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(current_speed);

    }
    else 
    {
        if (current_speed != 0) 
        {
            if (current_speed > 0)
            {
                current_speed -= speed_up * delta_Time;
            }
            else 
            {
                current_speed += speed_up * delta_Time;
            }
        }
        
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
            dynamic_cast<b2RevoluteJoint*>(get_bodies()[3]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(speed_trunk);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
    {
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[3]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(-speed_trunk);
    }
    else 
    {
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[3]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        current_speed = 0.0;
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[1]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(current_speed);
        dynamic_cast<b2RevoluteJoint*>(get_bodies()[2]->get_body()->GetJointList()[0].joint)->SetMotorSpeed(current_speed);
    }
}
