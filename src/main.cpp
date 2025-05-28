#include <string.h>
#include "raylib.h"
#include "Settings.hpp"
#include "UI.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int main()
{
    Load("settings.txt");

    int flags = 0;
    flags |= FLAG_WINDOW_HIGHDPI;
    if (verticalSync) flags |= FLAG_VSYNC_HINT;
	SetConfigFlags(flags);

    InitWindow(windowSize[0], windowSize[1], "Sample Raylib Project");

    rlImGuiSetup(true);

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(DrawFrame, 0, 1);
    #else
        while (!WindowShouldClose())
        {
            DrawFrame();
        }
    #endif

    Save("settings.txt");
    rlImGuiShutdown();
	CloseWindow();

	return 0;
}
