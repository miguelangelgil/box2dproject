#include "scene.hpp"

Scene::Scene() :
    physics_world(new b2World(b2Vec2(0,-9.8f)))
{
}

Scene::Scene(Entity & entity):
    physics_world(new b2World(b2Vec2(0,-9.8f)))
{
    my_entities.push_back(&entity);
}

Scene::Scene(b2Vec2 gravity):
    physics_world(new b2World(gravity))
{
}

Scene::Scene(Entity & entity, b2Vec2 gravity):
    physics_world(new b2World(gravity))
{
    my_entities.push_back(&entity);
}

Scene::~Scene()
{
    for (auto&& entity : my_entities) 
    {
        physics_world->DestroyBody(entity->get_body()->get_body());
    }
}

void Scene::update(RenderWindow& window)
{
    for (auto&& entity : my_entities) 
    {
        entity->update(window);

    }
}

void Scene::draw(RenderWindow & window)
{
    for (auto&& entity : my_entities) 
    {
        entity->draw(window);
    }
}

void Scene::add_entity(Entity & entity)
{
    my_entities.push_back(&entity);
}

