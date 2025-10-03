#pragma once

#include <raylib.h>

extern bool isSettings;
extern Vector2 windowSize;

void DrawFrame();
void DrawSettings(bool* isOpen);
