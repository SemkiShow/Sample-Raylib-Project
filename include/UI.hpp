// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <imgui.h>
#include <raylib.h>
#include <rlImGui.h>

extern bool isSettings;
extern int menuOffset;
extern Vector2 windowSize;

void DrawFrame();
void ShowSettings(bool* isOpen);
void ShowMenuBar();
