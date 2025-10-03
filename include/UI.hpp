// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <raylib.h>

extern bool isSettings;
extern Vector2 windowSize;

void DrawFrame();
void DrawSettings(bool* isOpen);
