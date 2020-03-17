#pragma once
#include <box2d.h>
#include "entity.hpp"
class Scene 
{
private:

    float timeStep = 1.0f / 60.0f;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    std::vector<Entity> my_entities;


public:

    struct World 
    {
        b2Vec2 gravity;
        b2World world;
    };

    Scene();
    void update();
    void draw();
    void add_entity(Entity entity);

};