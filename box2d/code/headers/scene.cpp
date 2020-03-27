#include "scene.hpp"

Scene::Scene() :
    physics_world(new b2World(b2Vec2(0,-8.9f)))
{
    reference = *this;

}

Scene::Scene(Entity & entity):
    physics_world(new b2World(b2Vec2(0, -8.9f)))
{
    my_entities.push_back(&entity);
    reference = *this;
}

Scene::Scene(b2Vec2 gravity):
    physics_world(new b2World(gravity))
{
    reference = *this;
}

Scene::Scene(Entity & entity, b2Vec2 gravity):
    physics_world(new b2World(gravity))
{
    my_entities.push_back(&entity);
    reference = *this;
}

void Scene::update()
{
    for (auto&& entity : my_entities) 
    {
        entity->update();

    }
}

void Scene::draw()
{
    for (auto&& entity : my_entities) 
    {
        entity->draw();
    }
}

void Scene::add_entity(Entity & entity)
{
    my_entities.push_back(&entity);
}

