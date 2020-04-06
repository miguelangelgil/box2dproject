#include "entity.hpp"
#include <SFML/Window.hpp>

Entity::Entity(RigidBody& rigidbody, Mesh& mesh)
{
    my_mesh.push_back(&mesh);
    my_rigidbody.push_back(&rigidbody);
}

void Entity::update(RenderWindow& window, bool set_position)
{
    for (int i=0;i < my_rigidbody.size();i++)
    {

        for (b2Fixture* fixture = my_rigidbody[i]->get_body()->GetFixtureList(); fixture != nullptr; fixture = fixture->GetNext())
        {
            b2Shape::Type shape_type = fixture->GetType();

            if (shape_type == b2Shape::e_circle)
            {
                b2CircleShape* circle_shape = dynamic_cast<b2CircleShape*>(fixture->GetShape());
                float radius = circle_shape->m_radius;
                b2Vec2 center = circle_shape->m_p;
                CircleShape circle;
                circle.setPosition(my_mesh[i]->get_relative_position() + (box2d_position_to_sfml_position(b2Mul(my_rigidbody[i]->get_body()->GetTransform(),
                    center), float(window.getSize().y)) - Vector2f(radius, radius)));
                circle.setRadius(radius);
                circle.setFillColor(my_mesh[i]->get_color());
                window.draw(circle);

            }
            else if (shape_type == b2Shape::e_polygon)
            {
                b2PolygonShape* box2d_polygon = dynamic_cast<b2PolygonShape*>(fixture->GetShape());
                ConvexShape       sfml_polygon;

                int number_of_vertices = box2d_polygon->m_count;

                sfml_polygon.setPointCount(number_of_vertices);
                sfml_polygon.setFillColor(my_mesh[i]->get_color());

                for (int index = 0; index < number_of_vertices; index++)
                {
                    //float size = float(window.getSize().y);
                    sfml_polygon.setPoint
                    (
                        index,
                        (my_mesh[i]->get_relative_position() + box2d_position_to_sfml_position(b2Mul(my_rigidbody[i]->get_body()->GetTransform(), box2d_polygon->m_vertices[index]), float(window.getSize().y))
                            ));
                }
                window.draw(sfml_polygon);
            }
            else if (shape_type == b2Shape::e_edge)
            {
                // Se toman los dos vértices del segmento y se ajusta su posición usando el transform del body.
                // Los vértices resultantes se convierten y se ponen en un array para finalmente dibujar el segmento
                // que los une usando la sobrecarga del método draw() que permite dibujar primitivas de OpenGL a
                // partir de datos de vértices.

                b2EdgeShape* edge = dynamic_cast<b2EdgeShape*>(fixture->GetShape());

                b2Vec2 start = b2Mul(my_rigidbody[i]->get_body()->GetTransform(), edge->m_vertex1);
                b2Vec2 end = b2Mul(my_rigidbody[i]->get_body()->GetTransform(), edge->m_vertex2);

                Vertex line[] =
                {
                    Vertex(box2d_position_to_sfml_position(start, float(window.getSize().y)), Color::Green),
                    Vertex(box2d_position_to_sfml_position(end, float(window.getSize().y)), Color::Green),
                };

                window.draw(line, 2, Lines);
            }
        }
    }
       
               
}

RigidBody* Entity::get_body(int index)
{
    if(my_rigidbody.size() > index)
        return my_rigidbody[index];
    return nullptr;
}

void Entity::add_body(RigidBody& rigidbody, Mesh& mesh, Scene & scene)
{
    my_rigidbody.push_back(&rigidbody);
    b2RevoluteJointDef jointDef;
    jointDef.bodyA = my_rigidbody[0]->get_body();
    jointDef.bodyB = my_rigidbody[my_rigidbody.size()-1]->get_body();

    b2RevoluteJoint* joint = (b2RevoluteJoint*)scene.get_world()->CreateJoint(&jointDef);
    joints.push_back(*joint);
}
