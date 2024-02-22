#pragma once

#include "components/simple_scene.h"


namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

        Tema2();
        ~Tema2();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        void RenderPlayerTank();
    protected:
        glm::mat4 modelMatrix;
        ViewportArea miniViewportArea;

        float plane_size;
        float tank_body_side;
        float tank_turret_side;
        float tank_gun_side;
        float tank_tracks_side;

        float player_body_cx_moving, player_body_cy_moving, player_body_cz_moving;
        float player_turret_cx_moving, player_turret_cy_moving, player_turret_cz_moving;
        float player_turret_cx_aiming, player_turret_cy_aiming, player_turret_cz_aiming;
        float player_gun_cx_moving, player_gun_cy_moving, player_gun_cz_moving;
        float player_gun_cx_aiming_turret, player_gun_cy_aiming_turret, player_gun_cz_aiming_turret;
        float player_gun_cx_aiming, player_gun_cy_aiming, player_gun_cz_aiming;
        float player_tracks_cx_moving, player_tracks_cy_moving, player_tracks_cz_moving;

        float projectile_translateX, projectile_translateY, projectile_translateZ;
        float projectile_shooting;
        float projectile_angularStepOX, projectile_angularStepOY, projectile_angularStepOZ;

        float time;

        float player_translateX, player_translateY, player_translateZ;
        float player_scaleX, player_scaleY, player_scaleZ;
        float player_body_angularStepOX, player_body_angularStepOY, player_body_angularStepOZ;
        float player_turret_angularStepOX, player_turret_angularStepOY, player_turret_angularStepOZ;

    };
}