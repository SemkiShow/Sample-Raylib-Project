// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

struct Settings
{
    bool vsync = true;
    bool showFPS = true;

    void Save();
    void Load();
};

extern Settings settings;
