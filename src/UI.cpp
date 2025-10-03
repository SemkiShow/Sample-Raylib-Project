// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#include "UI.hpp"
#include "Settings.hpp"
#include <raygui.h>

#define UI_SPACING 30
#define ELEMENT_SIZE 30
#define ELEMENT_SPACING 10

bool isSettings = false;
Vector2 windowSize{16*50*2, 9*50*2};
bool lastVsync = vsync;

float nextElementPositionY = UI_SPACING * 2;

void DrawCheckBox(const char* text, bool* value)
{
    GuiCheckBox(Rectangle{UI_SPACING * 2, nextElementPositionY, ELEMENT_SIZE, ELEMENT_SIZE}, text, value);
    nextElementPositionY += ELEMENT_SIZE + ELEMENT_SPACING;
}

void DrawSettings(bool* isOpen)
{
    if (!*isOpen) return;
    DrawRectangleRounded(
            Rectangle{UI_SPACING, UI_SPACING, (float)GetScreenWidth() - UI_SPACING*2, (float)GetScreenHeight() - UI_SPACING*2}, 
            0.1f, 1, Color{128, 128, 128, 128});
    nextElementPositionY = UI_SPACING * 2;
    DrawCheckBox("vsync", &vsync);
    DrawCheckBox("show-fps", &showFPS);
}

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
