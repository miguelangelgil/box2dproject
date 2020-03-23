#include "scene.hpp"

Scene::Scene(Entity entity)
{
    my_entities.push_back(entity);
}

void Scene::update()
{
    for (auto&& entity : my_entities) 
    {
        entity.update();

    }
}

void Scene::draw()
{
    for (auto&& entity : my_entities) 
    {
        entity.draw();
    }
}

void Scene::add_entity(Entity entity)
{
    my_entities.push_back(entity);
}

