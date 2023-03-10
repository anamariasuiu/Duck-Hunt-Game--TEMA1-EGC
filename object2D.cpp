#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}
Mesh* object2D::CreateTriangle(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }


    triangle->InitFromData(vertices, indices);
    return triangle;
}
Mesh* object2D::CreateCircle(const std::string& name, glm::vec3 center, glm::vec3 color, float r)
{
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    float angle = RADIANS(2.0f * M_PI);
    float twicePi = 2.0f * M_PI;

    std::vector<VertexFormat> vertices;
    //{
    //    VertexFormat(center, color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(0 * twicePi / triangleAmount)), center.y + (r * sin(0 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(1 * twicePi / triangleAmount)), center.y + (r * sin(1 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(2 * twicePi / triangleAmount)), center.y + (r * sin(2 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(3 * twicePi / triangleAmount)), center.y + (r * sin(3 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(4 * twicePi / triangleAmount)), center.y + (r * sin(4 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(5 * twicePi / triangleAmount)), center.y + (r * sin(5 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(6 * twicePi / triangleAmount)), center.y + (r * sin(6 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(7 * twicePi / triangleAmount)), center.y + (r * sin(7 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(8 * twicePi / triangleAmount)), center.y + (r * sin(8 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(9 * twicePi / triangleAmount)), center.y + (r * sin(9 * twicePi / triangleAmount)),  0), color),
    //    VertexFormat(glm::vec3(center.x + (r * cos(10 * twicePi / triangleAmount)), center.y + (r * sin(10 * twicePi / triangleAmount)),  0), color)
    //    //VertexFormat(glm::vec3(x + (r * cos(9 * twicePi / triangleAmount)), y + (r * cos(9 * twicePi / triangleAmount)),  0), color),
    //    


    //};
    vertices.push_back(VertexFormat(center, color));
    for (int i = 0; i <= triangleAmount; i++) {
        glm::vec3 tmp(center.x + (r * cos(i * twicePi / triangleAmount)), center.y + (r * sin(i * twicePi / triangleAmount)), 0);
        vertices.push_back(VertexFormat(tmp, color));
    }

    std::vector<unsigned int> indices =
    {
        0,1,2,
        1,2,3,
        2,3,4,
        3,4,5,
        4,5,6,
        5,6,7,
        6,7,8,
        7,8,9,
        8,9,10,
        9,10,11,
        11,12,13,
        13,14,15,
        15,16,17,
        17,18,19,
        19,20,0,

        1,0,2,
        2,0,3,
        3,0,4,
        4,0,5,
        5,0,6,
        6,0,7,
        7,0,8,
        8,0,9,
        9,0,10,
        10,0,11,
        11,0,12,
        12,0,13,
        13,0,14,
        14,0,15,
        15,0,16,
        16,0,17,
        17,0,18,
        18,0,19,
        19,0,20,
        20,0,1


    };

    Mesh* cerc = new Mesh(name);
    //cerc->SetDrawMode(GL_TRIANGLE_FAN);
    cerc->InitFromData(vertices, indices);

    return cerc;
}