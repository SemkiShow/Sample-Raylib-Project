// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#include "Settings.hpp"
#include "UI.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

int main()
{
    Load();

#if !defined(PLATFORM_WEB)
    int flags = 0;
    if (vsync) flags |= FLAG_VSYNC_HINT;
    flags |= FLAG_WINDOW_HIGHDPI;
    flags |= FLAG_WINDOW_RESIZABLE;
    SetConfigFlags(flags);
#endif

    InitWindow(windowSize.x, windowSize.y, "SampleRaylibProject");
    SetExitKey(-1);

    rlImGuiSetup(true);

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(DrawFrame, 0, 1);
#else
    while (!WindowShouldClose())
    {
        DrawFrame();
    }
#endif

    Save();
    rlImGuiShutdown();
    CloseWindow();

    return 0;
}
