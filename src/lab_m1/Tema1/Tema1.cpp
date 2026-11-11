#include "lab_m1/Tema1/Tema1.h"
#include <iostream>

using namespace std;

namespace m1
{
    Tema1::Tema1()
    {
    }

    Tema1::~Tema1()
    {
    }

    // setam o camera ortogragica direct pe rezolutia ecranului
    // (0,0) - stanga jos, (width, height) dreapta sus
    void Tema1::Init()
    {
        glm::ivec2 resolution = window->GetResolution();
        auto camera = GetSceneCamera();
        camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
        camera->SetPosition(glm::vec3(0, 0, 50));
        camera->SetRotation(glm::vec3(0, 0, 0));
        camera->Update();
        // dezactivam controlul 3D al camerei
        GetCameraInput()->SetActive(false);
    }

    void Tema1::FrameStart()
    {
        glClearColor(0.15f, 0.15f, 0.18f, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::ivec2 resolution = window->GetResolution();
        glViewport(0, 0, resolution.x, resolution.y);
    }

    void Tema1::Update(float deltaTimeSeconds)
    {
    }

    void Tema1::FrameEnd()
    {
    }

    void Tema1::OnInputUpdate(float deltaTime, int mods) {}
    void Tema1::OnKeyPress(int key, int mods) {}
    void Tema1::OnKeyRelease(int key, int mods) {}
    void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) {}
    void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) {}
    void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) {}
    void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) {}
    void Tema1::OnWindowResize(int width, int height) {}
}   // namespace m1