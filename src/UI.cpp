// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#include "Settings.hpp"
#include "UI.hpp"
#include <raygui.h>
#include <raymath.h>

#define UI_SPACING 30
#define ELEMENT_SIZE 30
#define ELEMENT_SPACING 10

bool isSettings = false;
Vector2 g_windowSize{16 * 50 * 2, 9 * 50 * 2};
bool lastVsync = settings.vsync;

float nextElementPositionY = UI_SPACING * 2;

void DrawCheckBox(const char* text, bool* value)
{
    GuiCheckBox({UI_SPACING * 2, nextElementPositionY, ELEMENT_SIZE, ELEMENT_SIZE}, text, value);
    nextElementPositionY += ELEMENT_SIZE + ELEMENT_SPACING;
}

void UpdateWindowSize()
{
    g_windowSize = {(float)GetRenderWidth(), (float)GetRenderHeight()};
    g_windowSize /= GetWindowScaleDPI();
}

void DrawSettings()
{
    Rectangle rec = {UI_SPACING, UI_SPACING, g_windowSize.x - UI_SPACING * 2,
                     g_windowSize.y - UI_SPACING * 2};
    DrawRectangleRounded(rec, 0.1f, 1, Color{127, 127, 127, 127});
    nextElementPositionY = rec.y + UI_SPACING;
    DrawCheckBox("vsync", &settings.vsync);
    DrawCheckBox("show-fps", &settings.showFPS);
}

void DrawFrame()
{
    BeginDrawing();

    ClearBackground(BLACK);

    UpdateWindowSize();

    if (settings.showFPS) DrawFPS(0, 0);

    if (GuiButton({g_windowSize.x - ELEMENT_SIZE, 0, ELEMENT_SIZE, ELEMENT_SIZE}, "#142#"))
        isSettings = !isSettings;

    if (isSettings) DrawSettings();

    if (lastVsync != settings.vsync)
    {
        lastVsync = settings.vsync;
        if (!settings.vsync)
            ClearWindowState(FLAG_VSYNC_HINT);
        else
            SetWindowState(FLAG_VSYNC_HINT);
    }

    EndDrawing();
}
