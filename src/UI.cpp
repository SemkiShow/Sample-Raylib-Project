#define RAYGUI_IMPLEMENTATION
#include "UI.hpp"
#include "Settings.hpp"

bool isSettings = false;
int windowSize[2] = {16*50*2, 9*50*2};
bool lastVsync = vsync;

void DrawFrame()
{
    BeginDrawing();

    ClearBackground(BLACK);

    if (showFPS) DrawFPS(0, 0);

    if (GuiButton(Rectangle{(float)GetScreenWidth() - 30, 0, 30, 30}, "#142#")) isSettings = !isSettings;

    DrawSettings(&isSettings);

    if (lastVsync != vsync)
    {
        lastVsync = vsync;
        if (!vsync) ClearWindowState(FLAG_VSYNC_HINT);
        else SetWindowState(FLAG_VSYNC_HINT);
    }
    
    EndDrawing();
}

void DrawSettings(bool* isOpen)
{
    if (!*isOpen) return;
    DrawRectangleRounded(Rectangle{30, 30, (float)GetScreenWidth() - 60, (float)GetScreenHeight() - 60}, 0.1f, 1, Color{128, 128, 128, 128});
    GuiCheckBox(Rectangle{60, 60, 30, 30}, "vsync", &vsync);
    GuiCheckBox(Rectangle{60, 100, 30, 30}, "show-fps", &showFPS);
}
