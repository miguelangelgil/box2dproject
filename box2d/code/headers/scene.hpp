#pragma once
#include <memory>
#include <iostream>
#include <box2d.h>
#include "entity.hpp"

using namespace std;

class Scene 
{
private:

    float timeStep = 1.0f / 60.0f;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    std::vector<Entity> my_entities;

public:
    static Scene &reference;
public:

    struct World 
    {
        b2Vec2 gravity;
        shared_ptr< b2World > world;
    };

    Scene();
    Scene(Entity entity);
    void update();
    void draw();
    void add_entity(Entity entity);

};