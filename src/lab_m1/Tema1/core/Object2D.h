#pragma once

#include <string>
#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"

namespace Object2D {
    // dreptunghi plin sau contur simplu
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, bool fill = true);
    Mesh* CreateRectangleOutline(const std::string& name, glm::vec3 leftBottomCorner, float width, float height, glm::vec3 color, float borderWidth);

    Mesh* CreateTriangle(const std::string& name, glm::vec3 center, float size, glm::vec3 color, bool fill = true);
    Mesh* CreateCircle(const std::string& name, glm::vec3 center, float radius, glm::vec3 color, int numSegments = 32, bool fill = true);
    Mesh* CreateDiamond(const std::string& name, glm::vec3 center, float size, glm::vec3 color, bool fill = true);
    Mesh* CreatePlus(const std::string& name, glm::vec3 center, float size, glm::vec3 color);
    Mesh* CreateStar(const std::string& name, glm::vec3 center, float outerRadius, glm::vec3 color);
}