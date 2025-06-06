#include "Settings.hpp"
#include "UI.hpp"
#include <iostream>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

int main()
{
    Load("settings.txt");

    #if !defined(PLATFORM_WEB)
    int flags = 0;
    if (vsync) flags |= FLAG_VSYNC_HINT;
    flags |= FLAG_WINDOW_HIGHDPI;
    flags |= FLAG_WINDOW_RESIZABLE;
    SetConfigFlags(flags);
    #endif
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

    Save("settings.txt");
    CloseWindow();

	return 0;
}
