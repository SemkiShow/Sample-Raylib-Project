#include <string.h>
#include "raylib.h"
#include "Settings.hpp"
#include "UI.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void DrawFrame()
{
    BeginDrawing();

    rlImGuiBegin();

    ClearBackground(BLACK);

    ShowMenuBar();
    if (isSettings) ShowSettings(&isSettings);

    if (settings.showFPS) DrawText(("FPS: " + std::to_string(GetFPS())).data(), 0, menuOffset, 24, SKYBLUE);

    rlImGuiEnd();
    
    EndDrawing();
}

int main()
{
    settings.Load("settings.txt");

    int flags = 0;
    flags |= FLAG_WINDOW_HIGHDPI;
    if (settings.verticalSync) flags |= FLAG_VSYNC_HINT;
	SetConfigFlags(flags);

    InitWindow(windowSize[0], windowSize[1], "Sample Raylib Project");

    rlImGuiSetup(true);

    bool lastVsync = settings.verticalSync;

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(DrawFrame, 0, 1);
    #else
        while (!WindowShouldClose())
        {
            DrawFrame();
            if (lastVsync != settings.verticalSync)
            {
                lastVsync = settings.verticalSync;
                if (!settings.verticalSync) ClearWindowState(FLAG_VSYNC_HINT);
                else SetWindowState(FLAG_VSYNC_HINT);
            }
        }
    #endif

    settings.Save("settings.txt");
    rlImGuiShutdown();
	CloseWindow();

	return 0;
}
