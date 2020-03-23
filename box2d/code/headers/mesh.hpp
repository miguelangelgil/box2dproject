#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>
class Mesh
{
private:
    std::shared_ptr<sf::Shape> my_shape;

public:
    Mesh(std::string path);


};
