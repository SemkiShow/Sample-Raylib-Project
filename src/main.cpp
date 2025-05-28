#include "Settings.hpp"
#include "UI.hpp"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int main()
{
    #if not defined(PLATFORM_WEB)
    Load("settings.txt");
    #endif

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

    #if not defined(PLATFORM_WEB)
    Save("settings.txt");
    #endif
    rlImGuiShutdown();
	CloseWindow();

	return 0;
}
