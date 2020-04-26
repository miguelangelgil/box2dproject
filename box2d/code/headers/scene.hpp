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
    unique_ptr< b2World > physics_world;
public:
    /**
    Constructor de escena vacia
    */
    Scene();
    /**
    Constructor de escena con una entidad
    */
    Scene(Entity &entity);
    /**
    Constructor de escena inicializando valores de gravedad
    de mundo de box2d
    */
    Scene(b2Vec2 gravity);
    /**
    Constructor de escena con una entidad inicial e inicializando
    valores de gravedad de box2d
    */
    Scene(Entity &entity, b2Vec2 gravity);
    /**
    Destructor de scene
    */
    ~Scene();
    /**
    Clase encargada de actualizar todas las entities que tenga
    */
    void update();
    /**
    Clase encargada de dibujar todas la entiadades que tenga
    */
    void draw();
    /**
    Añade una entidad a la escena
    */
    void add_entity(Entity & entity);
    /**
    Retorna una referencia del mundo de box2d
    */
    b2World& get_world() 
    {
        return *physics_world;
    }

};