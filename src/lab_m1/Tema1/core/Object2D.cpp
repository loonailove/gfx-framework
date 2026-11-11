#include "Object2D.h"

#include <vector>
#include <cmath>
#include "core/engine.h"

namespace Object2D {
    // functia returneaza un pointer la un obiect de tip mesh
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill) {
        glm::vec3 corner = leftBottomCorner;

        // generam o lista cu cele 4 varfuri
        std::vector<VertexFormat> vertices = {
            VertexFormat(corner, color),                                // coltul din stanga jos
            VertexFormat(corner + glm::vec3(0, height, 0), color),      // coltul din stanga sus
            VertexFormat(corner + glm::vec3(width, height, 0), color),  // coltul din dreapta sus
            VertexFormat(corner + glm::vec3(width, 0, 0), color),       // coltul din dreapta jos
        };

        Mesh* rectangle = new Mesh(name);
        // cream vectorul de indici
        std::vector<unsigned int> indices;

        if (!fill) {
            // 0 -> 1 -> 2 -> 3 -> 0
            rectangle->SetDrawMode(GL_LINE_LOOP);
            indices = {
                0, 1,
                2, 3
            };
        } else {
            // implicit, folosim GL_TRIANGLES
            indices = {
                0, 1, 2,
                0, 2, 3
            };
        }

        rectangle->InitFromData(vertices, indices);
        return rectangle;
    }

    Mesh* CreateRectangleOutline(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, float borderWidth) {
        glm::vec3 corner = leftBottomCorner;
        float b = borderWidth;

        // avem nevoie de 8 noduri: 4 pt exterior, 4 pt interior
        std::vector<VertexFormat> vertices = {
            // exterior
            VertexFormat(corner, color),                                // coltul din stanga jos
            VertexFormat(corner + glm::vec3(0, height, 0), color),      // coltul din stanga sus
            VertexFormat(corner + glm::vec3(width, height, 0), color),  // coltul din dreapta sus
            VertexFormat(corner + glm::vec3(width, 0, 0), color),       // coltul din dreapta jos

            // interior
            VertexFormat(corner + glm::vec3(borderWidth, borderWidth, 0), color),                   // coltul din stanga jos
            VertexFormat(corner + glm::vec3(borderWidth, height - borderWidth, 0), color),          // coltul din stanga sus
            VertexFormat(corner + glm::vec3(width - borderWidth, height - borderWidth, 0), color), // coltul din dreapta sus
            VertexFormat(corner + glm::vec3(width - borderWidth, borderWidth, 0), color),           // coltul din drapta jos
        };

        Mesh* rectangle = new Mesh(name);
        // cream vectorul de indici
        std::vector<unsigned int> indices;

        indices = {
            0, 1, 5,    0, 5, 4,
            1, 5, 6,    1, 6, 2,
            2, 6, 7,    2, 7, 3,
            0, 3, 4,    3, 4, 7,
        };

        rectangle->InitFromData(vertices, indices);
        return rectangle;
    }

    Mesh* CreateCircle(const std::string& name, glm::vec3 center, float radius, glm::vec3 color, int numSegments, bool fill) {
        std::vector<VertexFormat> vertices;
        std::vector<unsigned int> indices;

        Mesh* circle = new Mesh(name);

        if (fill) {
            // punem centrul cercului in lista de vertecsi
            vertices.push_back(VertexFormat(center, color));

            for (int i = 0; i <= numSegments; ++i) {
                float theta = 2.0f * M_PI * 1 / float(numSegments);
                theta *= i;

                // deplasarea pe axa X
                float x = radius * std::cos(theta);
                // deplasarea pe axa Y
                float y = radius * std::sin(theta);
                vertices.push_back(VertexFormat(center + glm::vec3(x, y, 0), color));
            }

            for (int i = 1; i <= numSegments; ++i) {
                indices.push_back(0);
                indices.push_back(i);
                indices.push_back(i + 1);
            }
        } else {
            circle->SetDrawMode(GL_LINE_LOOP);

            for (int i = 0; i < numSegments; ++i) {
                float theta = 2.0f * M_PI * 1 / float(numSegments);
                theta *= i;

                // deplasarea pe axa X
                float x = radius * std::cos(theta);
                // deplasarea pe axa Y
                float y = radius * std::sin(theta);
                vertices.push_back(VertexFormat(center + glm::vec3(x, y, 0), color));
                indices.push_back(i);
            }
        }

        circle->InitFromData(vertices, indices);
        return circle;
    }

    Mesh* CreateTriangle(const std::string& name, glm::vec3 center, float size, glm::vec3 color, bool fill) {
        std::vector<VertexFormat> vertices;
        std::vector<unsigned int> indices;

        Mesh* triangle = new Mesh(name);

        float height = std::sqrt(3) / 2 * size;

        vertices = {
            VertexFormat(center + glm::vec3(0, 2 / 3 * height, 0), color),              // varf sus
            VertexFormat(center + glm::vec3(- size / 2, - 1 / 3 * height, 0), color),   // varf stanga
            VertexFormat(center + glm::vec3(size / 2, 1 / 3 * height, 0), color),       // varf dreapta
        };

        if (fill) {
            indices = {
                0, 1, 2,
            };
        } else {
            triangle->SetDrawMode(GL_LINE_LOOP);
            indices = {
                0, 1, 2,
            };
        }

        triangle->InitFromData(vertices, indices);
        return triangle;
    }

    Mesh* createDiamond(const std::string& name, glm::vec3 center, float size, glm::vec3 color, bool fill) {
        float half = size / std::sqrt(2);

        Mesh* diamond = new Mesh(name);

        std::vector<VertexFormat> vertices = {
            VertexFormat(center + glm::vec3(0, half, 0), color),    // sus
            VertexFormat(center + glm::vec3(0, -half, 0), color),   // jos
            VertexFormat(center + glm::vec3(half, 0, 0), color),    // dreapta
            VertexFormat(center + glm::vec3(-half, 0, 0), color),   // stanga
        };

        std::vector<unsigned int> indices;

        if (fill) {
            indices = {
                0, 2, 1,
                0, 3, 1,
            };
        } else {
            diamond->SetDrawMode(GL_LINE_LOOP);
            indices = {
                0, 3, 1, 2,
            };
        }

        diamond->InitFromData(vertices, indices);
        return diamond;
    }

    Mesh* Object2D::CreatePlus(const std::string& name, glm::vec3 center, float size, glm::vec3 color) {
        float armWidth = size / 3.0f;
        float halfSize = size / 2.0f;
        float halfArm = armWidth / 2.0f;

        std::vector<VertexFormat> vertices = {
            VertexFormat(center + glm::vec3(-halfArm, halfSize, 0), color),
            VertexFormat(center + glm::vec3(halfArm, halfSize, 0), color),
            VertexFormat(center + glm::vec3(halfArm, halfArm, 0), color),
            VertexFormat(center + glm::vec3(halfSize, halfArm, 0), color),
            VertexFormat(center + glm::vec3(halfSize, -halfArm, 0), color),
            VertexFormat(center + glm::vec3(halfArm, -halfArm, 0), color),
            VertexFormat(center + glm::vec3(halfArm, -halfSize, 0), color),
            VertexFormat(center + glm::vec3(-halfArm, -halfSize, 0), color),
            VertexFormat(center + glm::vec3(-halfArm, -halfArm, 0), color),
            VertexFormat(center + glm::vec3(-halfSize, -halfArm, 0), color),
            VertexFormat(center + glm::vec3(-halfSize, halfArm, 0), color),
            VertexFormat(center + glm::vec3(-halfArm, halfArm, 0), color)
        };

        std::vector<unsigned int> indices = {
            0, 1, 6, 0, 6, 7,
            9, 3, 4, 9, 4, 10
        };

        Mesh* plusMesh = new Mesh(name);
        plusMesh->InitFromData(vertices, indices);
        return plusMesh;
    }
}