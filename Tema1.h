#pragma once

#include "components/simple_scene.h"



namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void calculate_angle();

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy;
        glm::mat3 modelMatrix, modelMatrix1, modelMatrix2, modelMatrix3, modelMatrix4;
        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep, angularStep2, angle, alfa;
        int nr_frame = 0;
        glm::ivec2 rezolutie;
        int caz = 1, cadran, glont = 3, mouseOx, mouseOy, nr_escaped = 0, scor =0, nr_rate =0, speed =100, i= 0;
        float x = 150, y = 70, time = 0,x_drept = 0,y_drept = 0, Sx = 0, Sy =1;
        bool escaped = false, shooted = false;
        bool x_creste, y_creste, onclick = false;

        // TODO(student): If you need any other class variables, define them here.


    };
}   // namespace m1