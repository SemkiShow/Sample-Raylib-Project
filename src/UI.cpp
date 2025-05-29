#include "UI.hpp"
#include "Settings.hpp"

bool isSettings = false;
int menuOffset = 20;
int windowSize[2] = {16*50*2, 9*50*2};
bool lastVsync = verticalSync;

void DrawFrame()
{
    BeginDrawing();

    rlImGuiBegin();

    ClearBackground(BLACK);

    ShowMenuBar();
    if (isSettings) ShowSettings(&isSettings);

    if (showFPS) DrawFPS(0, 0);
    
    if (lastVsync != verticalSync)
    {
        lastVsync = verticalSync;
        if (!verticalSync) ClearWindowState(FLAG_VSYNC_HINT);
        else SetWindowState(FLAG_VSYNC_HINT);
    }

    rlImGuiEnd();
    
    EndDrawing();
}

void ShowSettings(bool* isOpen)
{
    if (!ImGui::Begin("Settings", isOpen))
    {
        ImGui::End();
        return;
    }
    ImGui::Checkbox("vsync", &verticalSync);
    ImGui::Checkbox("show-fps", &showFPS);
    ImGui::End();
}

void ShowMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Menu"))
        {
            if (ImGui::MenuItem("Settings"))
            {
                isSettings = true;
                ShowSettings(&isSettings);
            }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
    return;
}
