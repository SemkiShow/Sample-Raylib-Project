#include "UI.hpp"
#include "Settings.hpp"

bool isSettings = false;
int menuOffset = 20;
int windowSize[2] = {16*50*2, 9*50*2};

void ShowSettings(bool* isOpen)
{
    if (!ImGui::Begin("Settings", isOpen))
    {
        ImGui::End();
        return;
    }
    ImGui::Checkbox("vsync", &settings.verticalSync);
    ImGui::Checkbox("show-fps", &settings.showFPS);
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
