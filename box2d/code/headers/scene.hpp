#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <box2d.h>
#include "entity.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Entity;
class Scene 
{
private:

    float timeStep = 1.0f / 60.0f;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    vector<Entity *> my_entities;
    shared_ptr< b2World > physics_world;
public:

    Scene();
    Scene(Entity &entity);
    Scene(b2Vec2 gravity);
    Scene(Entity &entity, b2Vec2 gravity);
    void update();
    void draw(RenderWindow & window);
    void add_entity(Entity & entity);
    shared_ptr<b2World> get_world() 
    {
        return physics_world;
    }

};