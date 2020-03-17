#include "scene.hpp"

void Scene::update()
{
    for (auto&& entity :my_entities) 
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

void Scene::add_entity()
{
}
