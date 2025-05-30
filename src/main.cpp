#include "Settings.hpp"
#include "UI.hpp"
#include <iostream>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int main()
{
    #if !defined(PLATFORM_WEB)
    Load("settings.txt");
    #endif

    int flags = 0;
    if (vsync) flags |= FLAG_VSYNC_HINT;
    #if !defined(PLATFORM_WEB)
    flags |= FLAG_WINDOW_HIGHDPI;
    flags |= FLAG_WINDOW_RESIZABLE;
	#endif
    SetConfigFlags(flags);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);

    InitWindow(windowSize[0], windowSize[1], "Sample Raylib Project");
    SetExitKey(-1);

    GuiSetFont(GetFontDefault());

    #if defined(PLATFORM_WEB)
        emscripten_set_main_loop(DrawFrame, 0, 1);
    #else
        while (!WindowShouldClose())
        {
            DrawFrame();
        }
    #endif

    #if !defined(PLATFORM_WEB)
    Save("settings.txt");
	#endif
    CloseWindow();

	return 0;
}
