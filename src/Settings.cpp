// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#include "Settings.hpp"
#include <fstream>

Settings settings;

void Settings::Save()
{
    std::ofstream file("settings.txt");
    file << "vsync=" << (vsync ? "true" : "false") << '\n';
    file << "show-fps=" << (showFPS ? "true" : "false") << '\n';
    file.close();
}

void Settings::Load()
{
    std::ifstream file("settings.txt");
    std::string buf, label, value;
    while (std::getline(file, buf))
    {
        size_t equalSign = buf.find_first_of('=');
        if (equalSign == buf.npos) continue;
        label = buf.substr(0, equalSign);
        value = buf.substr(equalSign + 1);

        if (label == "vsync") vsync = value == "true";
        if (label == "show-fps") showFPS = value == "true";
    }
    file.close();
}
