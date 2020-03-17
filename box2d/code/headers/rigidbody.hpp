#pragma once
#include<iostream>
#include <box2d.h>
#include "values.hpp"
class RigidBody 
{
private:
    std::shared_ptr<b2Body> my_body;
    

public:
    RigidBody(body_kind my_body_kind, position_2d position, size_2d size, float density,float friction, float rotation = 0.0f);


};
