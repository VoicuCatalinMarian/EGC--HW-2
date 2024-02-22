#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace object3D
{
    Mesh* CreatePlane(const std::string& name, glm::vec3 leftBottomCorner, float side, glm::vec3 color);
    Mesh* CreateTankBody(const std::string& name, glm::vec3 leftBottomCorner, float width, glm::vec3 color, glm::vec3 corner_color);
    Mesh* CreateTankTurret(const std::string& name, glm::vec3 leftBottomCorner, float width, glm::vec3 color, glm::vec3 corner_color);
    Mesh* CreateTankGun(const std::string& name, glm::vec3 leftBottomCorner, float width, glm::vec3 color, glm::vec3 corner_color);
    Mesh* CreateTankTracks(const std::string& name, glm::vec3 leftBottomCorner, float width, glm::vec3 color, glm::vec3 corner_color);
}