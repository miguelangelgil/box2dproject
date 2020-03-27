#pragma once
#include<iostream>
#include <box2d.h>
#include "values.hpp"
#include "scene.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
class RigidBody 
{
private:
    b2Body* my_body;
    b2BodyDef body_definition;
    

public:
    RigidBody(Scene & scene ,Body_kind my_body_kind, Vector2f position, Vector2f size, float density,float friction, float rotation = 0.0f);


};
