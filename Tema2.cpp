#include "Tema2.h"

#include <vector>
#include <string>
#include <iostream>
#include <math.h>

#include "transform3D.h"
#include "object3D.h"

using namespace std;
using namespace m1;

Tema2::Tema2()
{
}

Tema2::~Tema2()
{
}

void Tema2::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    miniViewportArea = ViewportArea(50, 50, resolution.x / 5.f, resolution.y / 5.f);

    glm::vec3 corner = glm::vec3(0, 0, 0);

    plane_size = 100;

    Mesh* plane = object3D::CreatePlane("plane", corner, plane_size, glm::vec3(0.4f, 0.45f, 0.4f));
    AddMeshToList(plane);

    tank_body_side = 1;
    player_body_cx_moving = corner.x + 0.4775f * tank_body_side;
    player_body_cy_moving = corner.y + 0.155f * tank_body_side;
    player_body_cz_moving = corner.z + -0.25f * tank_body_side;

    tank_turret_side = tank_body_side / 3;
    player_turret_cx_moving = corner.x + 0.4775f * tank_body_side;
    player_turret_cy_moving = corner.y + 0.155f * tank_body_side;
    player_turret_cz_moving = corner.z + 0.25f * tank_body_side;
    player_turret_cx_aiming = corner.x + 0.55f * tank_turret_side;
    player_turret_cy_aiming = corner.y + 0.175f * tank_turret_side;
    player_turret_cz_aiming = corner.z + 0.35f * tank_turret_side;

    tank_gun_side = tank_body_side / 60;
    player_gun_cx_moving = corner.x + 0.4775f * tank_body_side;
    player_gun_cy_moving = corner.y + 0.155f * tank_body_side;
    player_gun_cz_moving = corner.z + 0.25f * tank_body_side;
    player_gun_cx_aiming_turret = corner.x + 0.55f * tank_turret_side;
    player_gun_cz_aiming_turret = corner.y + 0.175f * tank_turret_side;
    player_gun_cy_aiming_turret = corner.z + 0.35f * tank_turret_side;
    player_gun_cx_aiming = corner.x;
    player_gun_cy_aiming = corner.y + 0.5f * tank_gun_side;
    player_gun_cz_aiming = corner.z + 1.8675f * tank_gun_side;

    tank_tracks_side = tank_body_side;
    player_tracks_cx_moving = corner.x + 0.4775f * tank_body_side;
    player_tracks_cy_moving = corner.y + 0.155f * tank_body_side;
    player_tracks_cz_moving = corner.z + 0.25f * tank_body_side;

    player_translateX = 0;
    player_translateY = 0;
    player_translateZ = 0;
    player_body_angularStepOX = 0;
    player_body_angularStepOY = 0;
    player_body_angularStepOZ = 0;
    player_turret_angularStepOX = 0;
    player_turret_angularStepOY = 0;
    player_turret_angularStepOZ = 0;

    projectile_translateX = 0;
    projectile_translateY = 0;
    projectile_translateZ = 0;
    projectile_shooting = 0;
    projectile_angularStepOX = 0;
    projectile_angularStepOY = 0;
    projectile_angularStepOZ = 0;

    time = 0;

    Mesh* player_body = object3D::CreateTankBody("player_body", corner, tank_body_side, glm::vec3(0.05f, 0.15f, 0.05f), glm::vec3(0.05f, 0.175f, 0.05f));
    AddMeshToList(player_body);

    Mesh* player_turret = object3D::CreateTankTurret("player_turret", corner, tank_turret_side, glm::vec3(0.075f, 0.19f, 0.075f), glm::vec3(0.075f, 0.23f, 0.075f));
    AddMeshToList(player_turret);

    Mesh* player_gun = object3D::CreateTankGun("player_gun", corner, tank_gun_side, glm::vec3(0.3f, 0.35f, 0.35f), glm::vec3(0.32f, 0.37f, 0.37f));
    AddMeshToList(player_gun);

    Mesh* player_tracks = object3D::CreateTankTracks("player_tracks", corner, tank_tracks_side, glm::vec3(0.3f, 0.35f, 0.35f), glm::vec3(0.32f, 0.37f, 0.37f));
    AddMeshToList(player_tracks);

    Mesh* projectile = new Mesh("projectile");
    projectile->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
    meshes[projectile->GetMeshID()] = projectile;
}

void Tema2::FrameStart()
{
    glClearColor(0, 0, 0, 1);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();

    DrawCoordinateSystem();
}

void Tema2::Update(float deltaTimeSeconds)
{
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Scale(100, 100, 100);
    RenderMesh(meshes["plane"], shaders["VertexColor"], modelMatrix);

    if (projectile_shooting == 1)
    {
        projectile_translateX += cos(projectile_angularStepOY) * deltaTimeSeconds * 10;
        projectile_translateZ -= -sin(projectile_angularStepOY) * deltaTimeSeconds * 10;
    }

    time += deltaTimeSeconds;

    if (time >= 60)
        exit(1);

    RenderPlayerTank();
}

void Tema2::FrameEnd()
{
}

void Tema2::RenderPlayerTank()
{
    modelMatrix = glm::mat4(1);
    modelMatrix *= transform3D::Translate(-0.5f * tank_body_side, 0.014f * tank_body_side, 0.25f * tank_body_side);
    modelMatrix *= transform3D::Translate(player_translateX, player_translateY, player_translateZ);
    modelMatrix *= transform3D::Translate(player_body_cx_moving , player_body_cy_moving, player_body_cz_moving);
    modelMatrix *= transform3D::RotateOY(player_body_angularStepOY);
    modelMatrix *= transform3D::Translate(-player_body_cx_moving, -player_body_cy_moving, -player_body_cz_moving);
    RenderMesh(meshes["player_body"], shaders["VertexColor"], modelMatrix);

    modelMatrix *= transform3D::Scale(1.18f, 0.6f, 0.9f);
    modelMatrix *= transform3D::Translate(-0.135f * tank_body_side, 0.075f * tank_body_side, 0.0475 * tank_body_side);
    RenderMesh(meshes["player_tracks"], shaders["VertexColor"], modelMatrix);

    modelMatrix *= transform3D::Translate(0, 0, -0.5f * tank_body_side);
    RenderMesh(meshes["player_tracks"], shaders["VertexColor"], modelMatrix);

    modelMatrix *= transform3D::Scale(0.85f, 1.65f, 1.1f);
    modelMatrix *= transform3D::Translate(0.35f * tank_body_side, 0.19f * tank_body_side, 0.28f * tank_body_side);
    modelMatrix *= transform3D::Translate(player_turret_cx_aiming, player_turret_cy_aiming, -player_turret_cz_aiming);
    modelMatrix *= transform3D::RotateOY(player_turret_angularStepOY);
    modelMatrix *= transform3D::Translate(-player_turret_cx_aiming, -player_turret_cy_aiming, player_turret_cz_aiming);
    RenderMesh(meshes["player_turret"], shaders["VertexColor"], modelMatrix);

    modelMatrix *= transform3D::Translate(0.9f * tank_turret_side, 0.168f * tank_turret_side, -0.45f * tank_turret_side);
    RenderMesh(meshes["player_gun"], shaders["VertexColor"], modelMatrix);

    modelMatrix *= transform3D::Scale(0.06f, 0.06f, 0.06f);
    modelMatrix *= transform3D::Translate(10.5f, 0.15f, 0.5f);
    modelMatrix *= transform3D::Translate(projectile_translateX, projectile_translateY, projectile_translateZ);
    RenderMesh(meshes["projectile"], shaders["VertexColor"], modelMatrix);

}

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
    if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        if (window->KeyHold(GLFW_KEY_W))
        {
            player_translateX += cos(player_body_angularStepOY) * deltaTime / 1.5f;
            player_translateZ += -sin(player_body_angularStepOY) * deltaTime / 1.5f;
        }
        if (window->KeyHold(GLFW_KEY_A))
        {
            player_body_angularStepOY += deltaTime;
        }
        if (window->KeyHold(GLFW_KEY_S))
        {
            player_translateX -= cos(player_body_angularStepOY) * deltaTime / 1.5f;
            player_translateZ -= -sin(player_body_angularStepOY) * deltaTime / 1.5f;
        }
        if (window->KeyHold(GLFW_KEY_D))
        {
            player_body_angularStepOY -= deltaTime;
        }
    }

}

void Tema2::OnKeyPress(int key, int mods)
{
}

void Tema2::OnKeyRelease(int key, int mods)
{
}

void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        float sensivityOX = 0.001f;
        float sensivityOY = 0.001f;

        if (!window->GetSpecialKeyState()) {
            player_turret_angularStepOY -= sensivityOY * deltaX * 10;
        }

        if (window->GetSpecialKeyState()) {
            player_turret_angularStepOY += sensivityOY * deltaX * 10;
        }
    }
}

void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT))
    {
        projectile_shooting = 1;
        projectile_translateX = player_translateX;
        projectile_translateZ = player_translateZ;
        projectile_angularStepOY = player_body_angularStepOY;
    }
}

void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema2::OnWindowResize(int width, int height)
{
}