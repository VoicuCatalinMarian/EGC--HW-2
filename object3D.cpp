#include "object3D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* object3D::CreatePlane(const std::string& name, glm::vec3 leftBottomCorner, float side, glm::vec3 color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-1, 0, 1), color), // 0
        VertexFormat(corner + glm::vec3(1, 0, 1), color), // 1
        VertexFormat(corner + glm::vec3(1, 0, -1), color), // 2
        VertexFormat(corner + glm::vec3(-1, 0, -1), color), // 3

    };

    Mesh* plane = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        0, 1, 2,
        0, 2, 3,
    };

    plane->InitFromData(vertices, indices);
    return plane;
}


Mesh* object3D::CreateTankBody(const std::string& name, glm::vec3 leftBottomCorner, float side, glm::vec3 color, glm::vec3 corner_color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        // Right side

        VertexFormat(corner + glm::vec3(0, 0, 0), color), // 0
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.05f * side, 0), color), // 1
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.15f * side, 0), color), // 2
        VertexFormat(corner + glm::vec3(0, 0.2f * side, 0), color), // 3
        VertexFormat(corner + glm::vec3(0.8f * side, 0.2f * side, 0), color), // 4
        VertexFormat(corner + glm::vec3(side, 0.075f * side, 0), color), // 5
        VertexFormat(corner + glm::vec3(0.85f * side, 0, 0), color), // 6

        // Right side corners outside

        VertexFormat(corner + glm::vec3(0, -0.01f * side, -0.01f * side), corner_color), // 7
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.05f * side, -0.01f * side), corner_color), // 8
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.15f * side, -0.01f * side), corner_color), // 9
        VertexFormat(corner + glm::vec3(0, 0.21f * side, -0.01f * side), corner_color), // 10
        VertexFormat(corner + glm::vec3(0.8f * side, 0.21f * side, -0.01f * side), corner_color), // 11
        VertexFormat(corner + glm::vec3(1.01f * side, 0.075f * side, -0.01f * side), corner_color), // 12
        VertexFormat(corner + glm::vec3(0.85f * side, -0.01f * side, -0.01f * side), corner_color), // 13

        // Left side

        VertexFormat(corner + glm::vec3(0, 0, -0.5f * side), color), // 14
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.05f * side, -0.5f * side), color), // 15
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.15f * side, -0.5f * side), color), // 16
        VertexFormat(corner + glm::vec3(0, 0.2f * side, -0.5f * side), color), // 17
        VertexFormat(corner + glm::vec3(0.8f * side, 0.2f * side, -0.5f * side), color), // 18
        VertexFormat(corner + glm::vec3(side, 0.075f * side, -0.5f * side), color), // 19
        VertexFormat(corner + glm::vec3(0.85f * side, 0, -0.5f * side), color), // 20

        // Left side corners outside

        VertexFormat(corner + glm::vec3(0, -0.01f * side, -0.49f * side), corner_color), // 21
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.05f * side, -0.49f * side), corner_color), // 22
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.15f * side, -0.49f * side), corner_color), // 23
        VertexFormat(corner + glm::vec3(0, 0.21f * side, -0.49f * side), corner_color), // 24
        VertexFormat(corner + glm::vec3(0.8f * side, 0.21f * side, -0.49f * side), corner_color), // 25
        VertexFormat(corner + glm::vec3(1.01f * side, 0.075f * side, -0.49f * side), corner_color), // 26
        VertexFormat(corner + glm::vec3(0.85f * side, -0.01f * side, -0.49f * side), corner_color), // 27

        // Right side corners inside

        VertexFormat(corner + glm::vec3(0.01f * side, -0.01f * side, -0.02f * side), color), // 28
        VertexFormat(corner + glm::vec3(0, -0.01f * side, -0.02f * side), corner_color), // 29
        VertexFormat(corner + glm::vec3(-0.01f * side, 0, -0.02f * side), color), // 30
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.04f * side, -0.02f * side), color), // 31
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.05f * side, -0.02f * side), corner_color), // 32
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.06f * side, -0.02f * side), color), // 33
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.14f * side, -0.02f * side), color), // 34
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.15f * side, -0.02f * side), corner_color), // 35
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.16f * side, -0.02f * side), color), // 36
        VertexFormat(corner + glm::vec3(-0.01f * side, 0.2f * side, -0.02f * side), color), // 37
        VertexFormat(corner + glm::vec3(0, 0.21f * side, -0.02f * side), corner_color), // 38
        VertexFormat(corner + glm::vec3(0.03f * side, 0.23f * side, -0.02f * side), color), // 39
        VertexFormat(corner + glm::vec3(0.77f * side, 0.23f * side, -0.02f * side), color), // 40
        VertexFormat(corner + glm::vec3(0.8f * side, 0.21f * side, -0.02f * side), corner_color), // 41
        VertexFormat(corner + glm::vec3(0.81f * side, 0.205f * side, -0.02f * side), color), // 42
        VertexFormat(corner + glm::vec3(1.005f * side, 0.08f * side, -0.02f * side), color), // 43
        VertexFormat(corner + glm::vec3(1.01f * side, 0.075f * side, -0.02f * side), corner_color), // 45
        VertexFormat(corner + glm::vec3(1.005f * side, 0.07f * side, -0.02f * side), color), // 45
        VertexFormat(corner + glm::vec3(0.86f * side, -0.0075f * side, -0.02f * side), color), // 46
        VertexFormat(corner + glm::vec3(0.85f * side, -0.01f * side, -0.02f * side), corner_color), // 47
        VertexFormat(corner + glm::vec3(0.84f * side, -0.01f * side, -0.02f * side), color), // 48

        // Left side corners outside

        VertexFormat(corner + glm::vec3(0.01f * side, -0.01f * side, -0.48f * side), color), // 49
        VertexFormat(corner + glm::vec3(0, -0.01f * side, -0.48f * side), corner_color), // 50
        VertexFormat(corner + glm::vec3(-0.01f * side, 0, -0.48f * side), color), // 51
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.04f * side, -0.48f * side), color), // 52
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.05f * side, -0.48f * side), corner_color), // 53
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.06f * side, -0.48f * side), color), // 54
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.14f * side, -0.48f * side), color), // 55
        VertexFormat(corner + glm::vec3(-0.06f * side, 0.15f * side, -0.48f * side), corner_color), // 56
        VertexFormat(corner + glm::vec3(-0.05f * side, 0.16f * side, -0.48f * side), color), // 57
        VertexFormat(corner + glm::vec3(-0.01f * side, 0.2f * side, -0.48f * side), color), // 58
        VertexFormat(corner + glm::vec3(0, 0.21f * side, -0.48f * side), corner_color), // 59
        VertexFormat(corner + glm::vec3(0.03f * side, 0.23f * side, -0.48f * side), color), // 60
        VertexFormat(corner + glm::vec3(0.77f * side, 0.23f * side, -0.48f * side), color), // 61
        VertexFormat(corner + glm::vec3(0.8f * side, 0.21f * side, -0.48f * side), corner_color), // 62
        VertexFormat(corner + glm::vec3(0.81f * side, 0.205f * side, -0.48f * side), color), // 63
        VertexFormat(corner + glm::vec3(1.005f * side, 0.08f * side, -0.48f * side), color), // 64
        VertexFormat(corner + glm::vec3(1.01f * side, 0.075f * side, -0.48f * side), corner_color), // 65
        VertexFormat(corner + glm::vec3(1.005f * side, 0.07f * side, -0.48f * side), color), // 66
        VertexFormat(corner + glm::vec3(0.86f * side, -0.0075f * side, -0.48f * side), color), // 67
        VertexFormat(corner + glm::vec3(0.85f * side, -0.01f * side, -0.48f * side), corner_color), // 68
        VertexFormat(corner + glm::vec3(0.84f * side, -0.01f * side, -0.48f * side), color), // 69
    };

    Mesh* tank_body = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        // Right side

        0, 6, 4,
        0, 4, 3,
        0, 3, 2,
        0, 2, 1,
        4, 6, 5,

        // Left Side

        14, 18, 20,
        14, 17, 18,
        14, 16, 17,
        14, 15, 16,
        18, 19, 20,

        // Right side corners outside

        0, 13, 6,
        0, 7, 13,
        0, 1, 8,
        0, 8, 7,
        1, 2, 9,
        1, 9, 8,
        2, 3, 10,
        2, 10, 9,
        3, 4, 11,
        3, 11, 10,
        4, 5, 12,
        4, 12, 11,
        5, 6, 13,
        5, 13, 12,

        // Left side corners outside

        14, 20, 27,
        14, 27, 21,
        14, 22, 15,
        14, 21, 22,
        15, 23, 16,
        15, 22, 23,
        16, 24, 17,
        16, 23, 24,
        17, 25, 18,
        17, 24, 25,
        18, 26, 19,
        18, 25, 26,
        19, 27, 20,
        19, 26, 27,

        // Right side corners inside

        7, 30, 29,
        7, 29, 28,
        7, 8, 31,
        7, 31, 30,
        8, 33, 32,
        8, 32, 31,
        8, 9, 34,
        8, 34, 33,
        9, 36, 35,
        9, 35, 34,
        9, 10, 37,
        9, 37, 36,
        10, 39, 38,
        10, 38, 37,
        10, 11, 40,
        10, 40, 39,
        11, 42, 41,
        11, 41, 40,
        11, 12, 43,
        11, 43, 42,
        12, 45, 44,
        12, 44, 43,
        12, 13, 46,
        12, 46, 45,
        13, 48, 47,
        13, 47, 46,
        13, 7, 28,
        13, 28, 48,

        // Left side corners inside

        21, 49, 50,
        21, 50, 51,
        21, 51, 52,
        21, 52, 22,
        22, 52, 53,
        22, 53, 54,
        22, 54, 55,
        22, 55, 23,
        23, 55, 56,
        23, 56, 57,
        23, 57, 58,
        23, 58, 24,
        24, 58, 59,
        24, 59, 60,
        24, 60, 61,
        24, 61, 25,
        25, 61, 62,
        25, 62, 63,
        25, 63, 64,
        25, 64, 26,
        26, 64, 65,
        26, 65, 66,
        26, 66, 67,
        26, 67, 27,
        27, 67, 68,
        27, 68, 69,
        27, 69, 49,
        27, 49, 21,

        // Panels

        30, 31, 52,
        30, 52, 51,
        33, 34, 55,
        33, 55, 54,
        36, 37, 58,
        36, 58, 57,
        39, 40, 61,
        39, 61, 60,
        42, 43, 64,
        42, 64, 63,
        45, 46, 67,
        45, 67, 66,
        48, 28, 49,
        48, 49, 69,

        // Panel corners

        29, 30, 51,
        29, 51, 50,
        29, 50, 49,
        29, 49, 28,
        32, 33, 54,
        32, 54, 53,
        32, 53, 52,
        32, 52, 31,
        35, 36, 57,
        35, 57, 56,
        35, 56, 55,
        35, 55, 34,
        38, 39, 60,
        38, 60, 59,
        38, 59, 58,
        38, 58, 37,
        41, 42, 63,
        41, 63, 62,
        41, 62, 61,
        41, 61, 40,
        44, 45, 66,
        44, 66, 65,
        44, 65, 64,
        44, 64, 43,
        47, 48, 69,
        47, 69, 68,
        47, 68, 67,
        47, 67, 46,
    };

    tank_body->InitFromData(vertices, indices);
    return tank_body;
}

Mesh* object3D::CreateTankTurret(const std::string& name, glm::vec3 leftBottomCorner, float side, glm::vec3 color, glm::vec3 corner_color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        // First level

        VertexFormat(corner + glm::vec3(-0.02f * side, 0, 0.02f * side), corner_color), // 0
        VertexFormat(corner + glm::vec3(0.01f * side, 0.01f * side, 0.01f * side), color), // 1
        VertexFormat(corner + glm::vec3(0.14f * side, 0.01f * side, 0.14f * side), color), // 2
        VertexFormat(corner + glm::vec3(0.13f * side, 0, 0.17f * side), corner_color), // 3
        VertexFormat(corner + glm::vec3(0.16f * side, 0.01f * side, 0.15f * side), color), // 4
        VertexFormat(corner + glm::vec3(0.84f * side, 0.01f * side, 0.15f * side), color), // 5
        VertexFormat(corner + glm::vec3(0.87f * side, 0, 0.17f * side), corner_color), // 6
        VertexFormat(corner + glm::vec3(0.86f * side, 0.01f * side, 0.14f * side), color), // 7
        VertexFormat(corner + glm::vec3(1.09f * side, 0.01f * side, 0.01f * side), color), // 8
        VertexFormat(corner + glm::vec3(1.12f * side, 0, 0.02f * side), corner_color), // 9
        VertexFormat(corner + glm::vec3(1.1f * side, 0.01f * side, -0.01f * side), color), // 10
        VertexFormat(corner + glm::vec3(1.1f * side, 0.01f * side, -0.69f * side), color), // 11
        VertexFormat(corner + glm::vec3(1.12f * side, 0, -0.72f * side), corner_color), // 12
        VertexFormat(corner + glm::vec3(1.09f * side, 0.01f * side, -0.71f * side), color), // 13
        VertexFormat(corner + glm::vec3(0.86f * side, 0.01f * side, -0.84f * side), color), // 14
        VertexFormat(corner + glm::vec3(0.87f * side, 0, -0.87f * side), corner_color), // 15
        VertexFormat(corner + glm::vec3(0.84f * side, 0.01f * side, -0.85f * side), color), // 16
        VertexFormat(corner + glm::vec3(0.16f * side, 0.01f * side, -0.85f * side), color), // 17
        VertexFormat(corner + glm::vec3(0.13f * side, 0, -0.87f * side), corner_color), // 18
        VertexFormat(corner + glm::vec3(0.14f * side, 0.01f * side, -0.84f * side), color), // 19
        VertexFormat(corner + glm::vec3(0.01f * side, 0.01f * side, -0.71f * side), color), // 20
        VertexFormat(corner + glm::vec3(-0.02f * side, 0, -0.72f * side), corner_color), // 21
        VertexFormat(corner + glm::vec3(0, 0.01f * side, -0.69f * side), color), // 22
        VertexFormat(corner + glm::vec3(0, 0.01f * side, -0.01f * side), color), // 23

        // Second level
        
        VertexFormat(corner + glm::vec3(0, 0.3f * side, 0), corner_color), // 24
        VertexFormat(corner + glm::vec3(0.01f * side, 0.29f * side, 0.01f * side), color), // 25
        VertexFormat(corner + glm::vec3(0.14f * side, 0.29f * side, 0.14f * side), color), // 26
        VertexFormat(corner + glm::vec3(0.15f * side, 0.3f * side, 0.15f * side), corner_color), // 27
        VertexFormat(corner + glm::vec3(0.16f * side, 0.29f * side, 0.15f * side), color), // 28
        VertexFormat(corner + glm::vec3(0.84f * side, 0.29f * side, 0.15f * side), color), // 29
        VertexFormat(corner + glm::vec3(0.85f * side, 0.3f * side, 0.15f * side), corner_color), // 30
        VertexFormat(corner + glm::vec3(0.86f * side, 0.29f * side, 0.14f * side), color), // 31
        VertexFormat(corner + glm::vec3(1.09f * side, 0.19f * side, 0.01f * side), color), // 32
        VertexFormat(corner + glm::vec3(1.1f * side, 0.2f * side, 0), corner_color), // 33
        VertexFormat(corner + glm::vec3(1.1f * side, 0.19f * side, -0.01f * side), color), // 34
        VertexFormat(corner + glm::vec3(1.1f * side, 0.19f * side, -0.69f * side), color), // 35
        VertexFormat(corner + glm::vec3(1.1f * side, 0.2f * side, -0.7f * side), corner_color), // 36
        VertexFormat(corner + glm::vec3(1.09f * side, 0.19f * side, -0.71f * side), color), // 37
        VertexFormat(corner + glm::vec3(0.86f * side, 0.29f * side, -0.84f * side), color), // 38
        VertexFormat(corner + glm::vec3(0.85f * side, 0.3f * side, -0.85f * side), corner_color), // 39
        VertexFormat(corner + glm::vec3(0.84f * side, 0.29f * side, -0.85f * side), color), // 40
        VertexFormat(corner + glm::vec3(0.16f * side, 0.29f * side, -0.85f * side), color), // 41
        VertexFormat(corner + glm::vec3(0.15f * side, 0.3f * side, -0.85f * side), corner_color), // 42
        VertexFormat(corner + glm::vec3(0.14f * side, 0.29f * side, -0.84f * side), color), // 43
        VertexFormat(corner + glm::vec3(0.01f * side, 0.29f * side, -0.71f * side), color), // 44
        VertexFormat(corner + glm::vec3(0, 0.3f * side, -0.7f * side), corner_color), // 45
        VertexFormat(corner + glm::vec3(0, 0.29f * side, -0.69f * side), color), // 46
        VertexFormat(corner + glm::vec3(0, 0.29f * side, -0.01f * side), color), // 47

        VertexFormat(corner + glm::vec3(0.015f * side, 0.31f * side, 0.005f * side), color), // 48
        VertexFormat(corner + glm::vec3(0.145f * side, 0.31f * side, 0.125f * side), color), // 49
        VertexFormat(corner + glm::vec3(0.16f * side, 0.31f * side, 0.14f * side), color), // 50
        VertexFormat(corner + glm::vec3(0.84f * side, 0.31f * side, 0.14f * side), color), // 51
        VertexFormat(corner + glm::vec3(0.855f * side, 0.31f * side, 0.125f * side), color), // 52
        VertexFormat(corner + glm::vec3(1.085f * side, 0.21f * side, 0.005f * side), color), // 53
        VertexFormat(corner + glm::vec3(1.09f * side, 0.21f * side, -0.01f * side), color), // 54
        VertexFormat(corner + glm::vec3(1.09f * side, 0.21f * side, -0.69f * side), color), // 55
        VertexFormat(corner + glm::vec3(1.085f * side, 0.21f * side, -0.705f * side), color), // 56
        VertexFormat(corner + glm::vec3(0.855f * side, 0.31f * side, -0.825f * side), color), // 57
        VertexFormat(corner + glm::vec3(0.84f * side, 0.31f * side, -0.84f * side), color), // 58
        VertexFormat(corner + glm::vec3(0.16f * side, 0.31f * side, -0.84f * side), color), // 59
        VertexFormat(corner + glm::vec3(0.145f * side, 0.31f * side, -0.825f * side), color), // 60
        VertexFormat(corner + glm::vec3(0.015f * side, 0.31f * side, -0.705f * side), color), // 61
        VertexFormat(corner + glm::vec3(0.01f * side, 0.31f * side, -0.69f * side), color), // 62
        VertexFormat(corner + glm::vec3(0.01f * side, 0.31f * side, -0.01f * side), color), // 63

        // Third level

        VertexFormat(corner + glm::vec3(0.14f * side, 0.34f * side, 0.01f * side), color), // 64
        VertexFormat(corner + glm::vec3(0.15f * side, 0.35f * side, 0), corner_color), // 65
        VertexFormat(corner + glm::vec3(0.16f * side, 0.34f * side, 0.01f * side), color), // 66
        VertexFormat(corner + glm::vec3(0.84f * side, 0.34f * side, 0.01f * side), color), // 67
        VertexFormat(corner + glm::vec3(0.85f * side, 0.35f * side, 0), corner_color), // 68
        VertexFormat(corner + glm::vec3(0.86f * side, 0.34f * side, 0.01f * side), color), // 69
        VertexFormat(corner + glm::vec3(0.86f * side, 0.34f * side, -0.01f * side), color), // 70
        VertexFormat(corner + glm::vec3(0.86f * side, 0.34f * side, -0.69f * side), color), // 71
        VertexFormat(corner + glm::vec3(0.85f * side, 0.35f * side, -0.7f * side), corner_color), // 72
        VertexFormat(corner + glm::vec3(0.86f * side, 0.34f * side, -0.71f * side), color), // 73
        VertexFormat(corner + glm::vec3(0.84f * side, 0.34f * side, -0.71f * side), color), // 74
        VertexFormat(corner + glm::vec3(0.16f * side, 0.34f * side, -0.71f * side), color), // 75
        VertexFormat(corner + glm::vec3(0.15f * side, 0.35f * side, -0.7f * side), corner_color), // 76
        VertexFormat(corner + glm::vec3(0.14f * side, 0.34f * side, -0.71f * side), color), // 77
        VertexFormat(corner + glm::vec3(0.14f * side, 0.34f * side, -0.69f * side), color), // 78
        VertexFormat(corner + glm::vec3(0.14f * side, 0.34f * side, -0.01f * side), color), // 79

        VertexFormat(corner + glm::vec3(0.16f * side, 0.35f * side, -0.01f * side), color), // 80
        VertexFormat(corner + glm::vec3(0.84f * side, 0.35f * side, -0.01f * side), color), // 81
        VertexFormat(corner + glm::vec3(0.84f * side, 0.35f * side, -0.69f * side), color), // 82
        VertexFormat(corner + glm::vec3(0.16f * side, 0.35f * side, -0.69f * side), color), // 83



    };

    Mesh* tank_turret = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        // First level

        0, 2, 1,
        0, 3, 2,
        3, 5, 4,
        3, 6, 5,
        6, 8, 7,
        6, 9, 8,
        9, 11, 10,
        9, 12, 11,
        12, 14, 13,
        12, 15, 14,
        15, 17, 16,
        15, 18, 17,
        18, 20, 19,
        18, 21, 20,
        21, 23, 22,
        21, 0, 23,

        // Connection Between first and second level corners

        0, 1, 25,
        0, 25, 24,
        2, 3, 27,
        2, 27, 26,
        3, 4, 28,
        3, 28, 27,
        5, 6, 30,
        5, 30, 29,
        6, 7, 31,
        6, 31, 30,
        8, 9, 33,
        8, 33, 32,
        9, 10, 34,
        9, 34, 33,
        11, 12, 36,
        11, 36, 35,
        12, 13, 37,
        12, 37, 36,
        14, 15, 39,
        14, 39, 38,
        15, 16, 40,
        15, 40, 39,
        17, 18, 42,
        17, 42, 41,
        18, 19, 43,
        18, 43, 42,
        20, 21, 45,
        20, 45, 44,
        21, 22, 46,
        21, 46, 45,
        23, 0, 24,
        23, 24, 47,

        // Connection Between first and second level sides

        1, 2, 26,
        1, 26, 25,
        4, 5, 29,
        4, 29, 28,
        7, 8, 32,
        7, 32, 31,
        10, 11, 35,
        10, 35, 34,
        13, 14, 38,
        13, 38, 37,
        16, 17, 41,
        16, 41, 40,
        19, 20, 44,
        19, 44, 43,
        22, 23, 47,
        22, 47, 46,

        // Second level

        24, 25, 26,
        24, 26, 27,
        27, 28, 29,
        27, 29, 30,
        30, 31, 32,
        30, 32, 33,
        33, 34, 35,
        33, 35, 36,
        36, 37, 38,
        36, 38, 39,
        39, 40, 41,
        39, 41, 42,
        42, 43, 44,
        42, 44, 45,
        45, 46, 47,
        45, 47, 24,

        // Connection Between first and third levels

        24, 27, 49,
        24, 49, 48,
        27, 30, 51,
        27, 51, 50,
        30, 33, 53,
        30, 53, 52,
        33, 36, 55,
        33, 55, 54,
        36, 39, 57,
        36, 57, 56,
        39, 42, 59,
        39, 59, 58,
        42, 45, 61,
        42, 61, 60,
        45, 24, 63,
        45, 63, 62,

        // Third level corners

        24, 65, 79,
        24, 79, 63,
        24, 48, 64,
        24, 64, 65,
        27, 65, 64,
        27, 64, 49,
        27, 50, 66,
        27, 66, 65,
        30, 68, 67,
        30, 67, 51,
        30, 52, 69,
        30, 69, 68,
        33, 68, 69,
        33, 69, 53,
        33, 54, 70, 
        33, 70, 68,
        36, 72, 71,
        36, 71, 55,
        36, 56, 73, 
        36, 73, 72,
        39, 72, 73,
        39, 73, 57,
        39, 58, 74,
        39, 74, 72,
        42, 76, 75,
        42, 75, 59,
        42, 60, 77, 
        42, 77, 76,
        45, 76, 77,
        45, 77, 61,
        45, 62, 78,
        45, 78, 76,
        65, 66, 67,
        65, 67, 68,
        68, 70, 71,
        68, 71, 72,
        72, 74, 75,
        72, 75, 76,
        76, 78, 79,
        76, 79, 65,

        // Third level sides

        48, 49, 64,
        50, 51, 67,
        50, 67, 66,
        52, 53, 69,
        54, 55, 71,
        54, 71, 70,
        56, 57, 73,
        58, 59, 75,
        58, 75, 74,
        60, 61, 77,
        62, 63, 79,
        62, 79, 78,

        // Third level top

        80, 81, 82,
        80, 82, 83,
        65, 68, 81,
        65, 81, 80,
        68, 72, 82,
        68, 82, 81,
        72, 76, 83,
        73, 83, 82,
        77, 65, 80,
        77, 80, 83,
    };

    tank_turret->InitFromData(vertices, indices);
    return tank_turret;
}

Mesh* object3D::CreateTankGun(const std::string& name, glm::vec3 leftBottomCorner, float side, glm::vec3 color, glm::vec3 corner_color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        // Base circle

        VertexFormat(corner + glm::vec3(0, 0.5f * side, 1.8675f * side), color), // 0
        VertexFormat(corner, color), // 1
        VertexFormat(corner + glm::vec3(0, side, 0), color), // 2
        VertexFormat(corner + glm::vec3(0, 1.866f * side, 0.5f * side), color), // 3
        VertexFormat(corner + glm::vec3(0, 2.366f * side, 1.366f * side), color), // 4
        VertexFormat(corner + glm::vec3(0, 2.366f * side, 2.366f * side), color), // 5
        VertexFormat(corner + glm::vec3(0, 1.866f * side, 3.232f * side), color), // 6
        VertexFormat(corner + glm::vec3(0, side, 3.732f * side), color), // 7
        VertexFormat(corner + glm::vec3(0, 0, 3.732f * side), color), // 8
        VertexFormat(corner + glm::vec3(0, -0.866f * side, 3.232f * side), color), // 9
        VertexFormat(corner + glm::vec3(0, -1.366f * side, 2.366f * side), color), // 10
        VertexFormat(corner + glm::vec3(0, -1.366f * side, 1.366f * side), color), // 11
        VertexFormat(corner + glm::vec3(0, -0.866f * side, 0.5f * side), color), // 12

        //// Base circle corners inside

        //VertexFormat(corner + glm::vec3(0.1f * side, -0.1f * side, 0.01f * side), corner_color), // 13
        //VertexFormat(corner + glm::vec3(0.1f * side, 0.1f * side, -0.01f * side), corner_color), // 14
        //VertexFormat(corner + glm::vec3(0.1f * side, 0.9f * side, -0.01f * side), corner_color), // 15
        //VertexFormat(corner + glm::vec3(0.1f * side, 1.1f * side, 0.01f * side), corner_color), // 16
        //VertexFormat(corner + glm::vec3(0.1f * side, 1.966f * side, 0.49f * side), corner_color), // 17
        //VertexFormat(corner + glm::vec3(0.1f * side, 1.976f * side, 0.51f * side), corner_color), // 18
        //VertexFormat(corner + glm::vec3(0.1f * side, 2.466f * side, 1.356f * side), corner_color), // 19
        //VertexFormat(corner + glm::vec3(0.1f * side, 2.466f * side, 1.376f * side), corner_color), // 20
        //VertexFormat(corner + glm::vec3(0.1f * side, 2.466f * side, 2.356f * side), corner_color), // 21
        //VertexFormat(corner + glm::vec3(0.1f * side, 2.466f * side, 2.376f * side), corner_color), // 22
        //VertexFormat(corner + glm::vec3(0.1f * side, 1.966f * side, 3.222f * side), corner_color), // 23
        //VertexFormat(corner + glm::vec3(0.1f * side, 1.966f * side, 3.242f * side), corner_color), // 24
        //VertexFormat(corner + glm::vec3(0.1f * side, 1.1f * side, 3.722f * side), corner_color), // 25
        //VertexFormat(corner + glm::vec3(0.1f * side, 0.9f * side, 3.742f * side), corner_color), // 26
        //VertexFormat(corner + glm::vec3(0.1f * side, 0.1f * side, 3.742f * side), corner_color), // 27
        //VertexFormat(corner + glm::vec3(0.1f * side, -0.1f * side, 3.722f * side), corner_color), // 28
        //VertexFormat(corner + glm::vec3(0.1f * side, -0.966f * side, 3.242f * side), corner_color), // 29
        //VertexFormat(corner + glm::vec3(0.1f * side, -0.966f * side, 3.222f * side), corner_color), // 30
        //VertexFormat(corner + glm::vec3(0.1f * side, -1.466f * side, 2.376f * side), corner_color), // 31
        //VertexFormat(corner + glm::vec3(0.1f * side, -1.466f * side, 2.356f * side), corner_color), // 32
        //VertexFormat(corner + glm::vec3(0.1f * side, -1.466f * side, 1.376f * side), corner_color), // 33
        //VertexFormat(corner + glm::vec3(0.1f * side, -1.466f * side, 1.356f * side), corner_color), // 34
        //VertexFormat(corner + glm::vec3(0.1f * side, -0.966f * side, 0.51f * side), corner_color), // 35
        //VertexFormat(corner + glm::vec3(0.1f * side, -0.966f * side, 0.49f * side), corner_color), // 36

        //// Sides corners base

        //VertexFormat(corner + glm::vec3(0.2f * side, -0.1f * side, 0.01f * side), corner_color), // 37
        //VertexFormat(corner + glm::vec3(0.2f * side, 0.1f * side, -0.01f * side), corner_color), // 38
        //VertexFormat(corner + glm::vec3(0.2f * side, 0.9f * side, -0.01f * side), corner_color), // 39
        //VertexFormat(corner + glm::vec3(0.2f * side, 1.1f * side, 0.01f * side), corner_color), // 40
        //VertexFormat(corner + glm::vec3(0.2f * side, 1.966f * side, 0.49f * side), corner_color), // 41
        //VertexFormat(corner + glm::vec3(0.2f * side, 1.976f * side, 0.51f * side), corner_color), // 42
        //VertexFormat(corner + glm::vec3(0.2f * side, 2.466f * side, 1.356f * side), corner_color), // 43
        //VertexFormat(corner + glm::vec3(0.2f * side, 2.466f * side, 1.376f * side), corner_color), // 44
        //VertexFormat(corner + glm::vec3(0.2f * side, 2.466f * side, 2.356f * side), corner_color), // 45
        //VertexFormat(corner + glm::vec3(0.2f * side, 2.466f * side, 2.376f * side), corner_color), // 46
        //VertexFormat(corner + glm::vec3(0.2f * side, 1.966f * side, 3.222f * side), corner_color), // 47
        //VertexFormat(corner + glm::vec3(0.2f * side, 1.966f * side, 3.242f * side), corner_color), // 48
        //VertexFormat(corner + glm::vec3(0.2f * side, 1.1f * side, 3.722f * side), corner_color), // 49
        //VertexFormat(corner + glm::vec3(0.2f * side, 0.9f * side, 3.742f * side), corner_color), // 50
        //VertexFormat(corner + glm::vec3(0.2f * side, 0.1f * side, 3.742f * side), corner_color), // 51
        //VertexFormat(corner + glm::vec3(0.2f * side, -0.1f * side, 3.722f * side), corner_color), // 52
        //VertexFormat(corner + glm::vec3(0.2f * side, -0.966f * side, 3.242f * side), corner_color), // 53
        //VertexFormat(corner + glm::vec3(0.2f * side, -0.966f * side, 3.222f * side), corner_color), // 54
        //VertexFormat(corner + glm::vec3(0.2f * side, -1.466f * side, 2.376f * side), corner_color), // 55
        //VertexFormat(corner + glm::vec3(0.2f * side, -1.466f * side, 2.356f * side), corner_color), // 56
        //VertexFormat(corner + glm::vec3(0.2f * side, -1.466f * side, 1.376f * side), corner_color), // 57
        //VertexFormat(corner + glm::vec3(0.2f * side, -1.466f * side, 1.356f * side), corner_color), // 58
        //VertexFormat(corner + glm::vec3(0.2f * side, -0.966f * side, 0.51f * side), corner_color), // 59
        //VertexFormat(corner + glm::vec3(0.2f * side, -0.966f * side, 0.49f * side), corner_color), // 60
        //
        //// Sides corners top

        //VertexFormat(corner + glm::vec3(9.98f * side, -0.1f * side, 0.01f * side), corner_color), // 61
        //VertexFormat(corner + glm::vec3(9.98f * side, 0.1f * side, -0.01f * side), corner_color), // 62
        //VertexFormat(corner + glm::vec3(9.98f * side, 0.9f * side, -0.01f * side), corner_color), // 63
        //VertexFormat(corner + glm::vec3(9.98f * side, 1.1f * side, 0.01f * side), corner_color), // 64
        //VertexFormat(corner + glm::vec3(9.98f * side, 1.966f * side, 0.49f * side), corner_color), // 65
        //VertexFormat(corner + glm::vec3(9.98f * side, 1.976f * side, 0.51f * side), corner_color), // 66
        //VertexFormat(corner + glm::vec3(9.98f * side, 2.466f * side, 1.356f * side), corner_color), // 67
        //VertexFormat(corner + glm::vec3(9.98f * side, 2.466f * side, 1.376f * side), corner_color), // 68
        //VertexFormat(corner + glm::vec3(9.98f * side, 2.466f * side, 2.356f * side), corner_color), // 69
        //VertexFormat(corner + glm::vec3(9.98f * side, 2.466f * side, 2.376f * side), corner_color), // 70
        //VertexFormat(corner + glm::vec3(9.98f * side, 1.966f * side, 3.222f * side), corner_color), // 71
        //VertexFormat(corner + glm::vec3(9.98f * side, 1.966f * side, 3.242f * side), corner_color), // 72
        //VertexFormat(corner + glm::vec3(9.98f * side, 1.1f * side, 3.722f * side), corner_color), // 73
        //VertexFormat(corner + glm::vec3(9.98f * side, 0.9f * side, 3.742f * side), corner_color), // 74
        //VertexFormat(corner + glm::vec3(9.98f * side, 0.1f * side, 3.742f * side), corner_color), // 75
        //VertexFormat(corner + glm::vec3(9.98f * side, -0.1f * side, 3.722f * side), corner_color), // 76
        //VertexFormat(corner + glm::vec3(9.98f * side, -0.966f * side, 3.242f * side), corner_color), // 77
        //VertexFormat(corner + glm::vec3(9.98f * side, -0.966f * side, 3.222f * side), corner_color), // 78
        //VertexFormat(corner + glm::vec3(9.98f * side, -1.466f * side, 2.376f * side), corner_color), // 79
        //VertexFormat(corner + glm::vec3(9.98f * side, -1.466f * side, 2.356f * side), corner_color), // 80
        //VertexFormat(corner + glm::vec3(9.98f * side, -1.466f * side, 1.376f * side), corner_color), // 81
        //VertexFormat(corner + glm::vec3(9.98f * side, -1.466f * side, 1.356f * side), corner_color), // 82
        //VertexFormat(corner + glm::vec3(9.98f * side, -0.966f * side, 0.51f * side), corner_color), // 83
        //VertexFormat(corner + glm::vec3(9.98f * side, -0.966f * side, 0.49f * side), corner_color), // 84

        //// Top circle corners inside

        //VertexFormat(corner + glm::vec3(9.99f * side, -0.1f * side, 0.01f * side), corner_color), // 85
        //VertexFormat(corner + glm::vec3(9.99f * side, 0.1f * side, -0.01f * side), corner_color), // 86
        //VertexFormat(corner + glm::vec3(9.99f * side, 0.9f * side, -0.01f * side), corner_color), // 87
        //VertexFormat(corner + glm::vec3(9.99f * side, 1.1f * side, 0.01f * side), corner_color), // 88
        //VertexFormat(corner + glm::vec3(9.99f * side, 1.966f * side, 0.49f * side), corner_color), // 89
        //VertexFormat(corner + glm::vec3(9.99f * side, 1.976f * side, 0.51f * side), corner_color), // 90
        //VertexFormat(corner + glm::vec3(9.99f * side, 2.466f * side, 1.356f * side), corner_color), // 91
        //VertexFormat(corner + glm::vec3(9.99f * side, 2.466f * side, 1.376f * side), corner_color), // 92
        //VertexFormat(corner + glm::vec3(9.99f * side, 2.466f * side, 2.356f * side), corner_color), // 93
        //VertexFormat(corner + glm::vec3(9.99f * side, 2.466f * side, 2.376f * side), corner_color), // 94
        //VertexFormat(corner + glm::vec3(9.99f * side, 1.966f * side, 3.222f * side), corner_color), // 95
        //VertexFormat(corner + glm::vec3(9.99f * side, 1.966f * side, 3.242f * side), corner_color), // 96
        //VertexFormat(corner + glm::vec3(9.99f * side, 1.1f * side, 3.722f * side), corner_color), // 97
        //VertexFormat(corner + glm::vec3(9.99f * side, 0.9f * side, 3.742f * side), corner_color), // 98
        //VertexFormat(corner + glm::vec3(9.99f * side, 0.1f * side, 3.742f * side), corner_color), // 99
        //VertexFormat(corner + glm::vec3(9.99f * side, -0.1f * side, 3.722f * side), corner_color), // 100
        //VertexFormat(corner + glm::vec3(9.99f * side, -0.966f * side, 3.242f * side), corner_color), // 101
        //VertexFormat(corner + glm::vec3(9.99f * side, -0.966f * side, 3.222f * side), corner_color), // 102
        //VertexFormat(corner + glm::vec3(9.99f * side, -1.466f * side, 2.376f * side), corner_color), // 103
        //VertexFormat(corner + glm::vec3(9.99f * side, -1.466f * side, 2.356f * side), corner_color), // 104
        //VertexFormat(corner + glm::vec3(9.99f * side, -1.466f * side, 1.376f * side), corner_color), // 105
        //VertexFormat(corner + glm::vec3(9.99f * side, -1.466f * side, 1.356f * side), corner_color), // 106
        //VertexFormat(corner + glm::vec3(9.99f * side, -0.966f * side, 0.51f * side), corner_color), // 107
        //VertexFormat(corner + glm::vec3(9.99f * side, -0.966f * side, 0.49f * side), corner_color), // 108

        // Top Circle

        VertexFormat(corner + glm::vec3(40 * side, 0.5f * side, 1.8675f * side), color), // 13
        VertexFormat(corner + glm::vec3(40 * side, 0, 0), color), // 14
        VertexFormat(corner + glm::vec3(40 * side, side, 0), color), // 15
        VertexFormat(corner + glm::vec3(40 * side, 1.866f * side, 0.5f * side), color), // 16
        VertexFormat(corner + glm::vec3(40 * side, 2.366f * side, 1.366f * side), color), // 17
        VertexFormat(corner + glm::vec3(40 * side, 2.366f * side, 2.366f * side), color), // 18
        VertexFormat(corner + glm::vec3(40 * side, 1.866f * side, 3.232f * side), color), // 19
        VertexFormat(corner + glm::vec3(40 * side, side, 3.732f * side), color), // 20
        VertexFormat(corner + glm::vec3(40 * side, 0, 3.732f * side), color), // 21
        VertexFormat(corner + glm::vec3(40 * side, -0.866f * side, 3.232f * side), color), // 22
        VertexFormat(corner + glm::vec3(40 * side, -1.366f * side, 2.366f * side), color), // 23
        VertexFormat(corner + glm::vec3(40 * side, -1.366f * side, 1.366f * side), color), // 24
        VertexFormat(corner + glm::vec3(40 * side, -0.866f * side, 0.5f * side), color), // 25
    };

    Mesh* tank_gun = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        // Base cirle

        0, 1, 12,
        0, 12, 11,
        0, 11, 10,
        0, 10, 9,
        0, 9, 8,
        0, 8, 7,
        0, 7, 6,
        0, 6, 5,
        0, 5, 4,
        0, 4, 3,
        0, 3, 2,
        0, 2, 1,

        //// Base circle corners inside

        //1, 14, 13,
        //2, 16, 15,
        //3, 18, 17,
        //4, 20, 19,
        //5, 22, 21,
        //6, 24, 23,
        //7, 26, 25,
        //8, 28, 27,
        //9, 30, 29,
        //10, 32, 31,
        //11, 34, 33,
        //12, 36, 35,
        //1, 15, 14,
        //1, 2, 15,
        //2, 17, 16,
        //2, 3, 17,
        //3, 19, 18,
        //3, 4, 19,
        //4, 21, 20,
        //4, 5, 21,
        //5, 23, 22,
        //5, 6, 23,
        //6, 25, 24,
        //6, 7, 25,
        //7, 27, 26,
        //7, 8, 27,
        //8, 29, 28,
        //8, 9, 29,
        //9, 31, 30,
        //9, 10, 31,
        //10, 33, 32,
        //10, 11, 33,
        //11, 35, 34,
        //11, 12, 35,
        //12, 13, 36,
        //12, 1, 13,

        // Top circle

        13, 14, 25,
        13, 25, 24,
        13, 24, 23,
        13, 23, 22,
        13, 22, 21,
        13, 21, 20,
        13, 20, 19,
        13, 19, 18,
        13, 18, 17,
        13, 17, 16,
        13, 16, 15,
        13, 15, 14,

        // Sides

        1, 2, 15,
        1, 15, 14,
        2, 3, 16,
        2, 16, 15,
        3, 4, 17,
        3, 17, 16,
        4, 5, 18,
        4, 18, 17,
        5, 6, 19,
        5, 19, 18,
        6, 7, 20,
        6, 20, 19,
        7, 8, 21,
        7, 21, 20,
        8, 9, 22,
        8, 22, 21,
        9, 10, 23,
        9, 23, 22,
        10, 11, 24,
        10, 24, 23,
        11, 12, 25,
        11, 25, 24,
        12, 1, 14,
        12, 14, 25,

    };

    tank_gun->InitFromData(vertices, indices);
    return tank_gun;
}

Mesh* object3D::CreateTankTracks(const std::string& name, glm::vec3 leftBottomCorner, float side, glm::vec3 color, glm::vec3 corner_color)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        // Right side

        VertexFormat(corner + glm::vec3(0, 0, 0), color), // 0
        VertexFormat(corner + glm::vec3(0.1f * side, -0.1f * side, 0), color), // 1
        VertexFormat(corner + glm::vec3(0.9f * side, -0.1f * side, 0), color), // 2
        VertexFormat(corner + glm::vec3(side, 0, 0), color), // 3
        VertexFormat(corner + glm::vec3(side, 0.1f * side, 0), color), // 4
        VertexFormat(corner + glm::vec3(0.9f * side, 0.2f * side, 0), color), // 5
        VertexFormat(corner + glm::vec3(0.1f * side, 0.2f * side, 0), color), // 6
        VertexFormat(corner + glm::vec3(0, 0.1f * side, 0), color), // 7

        // Left side

        VertexFormat(corner + glm::vec3(0, 0, -0.15f * side), color), // 8
        VertexFormat(corner + glm::vec3(0.1f * side, -0.1f * side, -0.15f * side), color), // 9
        VertexFormat(corner + glm::vec3(0.9f * side, -0.1f * side, -0.15f * side), color), // 10
        VertexFormat(corner + glm::vec3(side, 0, -0.15f * side), color), // 11
        VertexFormat(corner + glm::vec3(side, 0.1f * side, -0.15f * side), color), // 12
        VertexFormat(corner + glm::vec3(0.9f * side, 0.2f * side, -0.15f * side), color), // 13
        VertexFormat(corner + glm::vec3(0.1f * side, 0.2f * side, -0.15f * side), color), // 14
        VertexFormat(corner + glm::vec3(0, 0.1f * side, -0.15f * side), color), // 15
    };

    Mesh* tank_tracks = new Mesh(name);
    std::vector<unsigned int> indices =
    {
        // Right side
        
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 7,

        // Connection panels
       
        0, 8, 1,
        1, 8, 9,
        1, 9, 2,
        2, 9, 10,
        2, 10, 3,
        3, 10, 11,
        3, 11, 4,
        4, 11, 12,
        4, 12, 5,
        5, 12, 13,
        5, 13, 6,
        6, 13, 14,
        6, 14, 7,
        7, 14, 15,
        7, 15, 0,
        0, 15, 8,

        // Left side

        8, 9, 10,
        8, 10, 11,
        8, 11, 12,
        8, 12, 13,
        8, 13, 14,
        8, 14, 15,
    };

    tank_tracks->InitFromData(vertices, indices);
    return tank_tracks;
}