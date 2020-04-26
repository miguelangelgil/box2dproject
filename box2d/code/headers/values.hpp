#pragma once
#include <iostream>
#include <box2d.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


struct Coord_2d
{
    float x = 0;
    float y = 0;
};
/**
Enumeracion que indica el tipo de cuerpo que es un rigidbody
*/
enum Body_kind
{
    STATIC,
    KINEMATIC,
    DYNAMIC,
    
};
/**
Enumeracion que indica el tipo de figura de sfml es
*/
enum TypeShape
{
    CONVEX = 0,
    CIRCLE = 1,
    CHAIN = 2,
    RECTANGLE=3,
};

/** En Box2D las coordenadas Y crecen hacia arriba y en SFML crecen hacia abajo desde el borde superior.
   ** Esta función se encarga de convertir el sistema de coordenadas para que la escena no se vea invertida.
   **/
inline Vector2f box2d_position_to_sfml_position(const b2Vec2& box2d_position, float window_height)
{
    return Vector2f(box2d_position.x, window_height - box2d_position.y);
}
