// SPDX-FileCopyrightText: 2025 SemkiShow
//
// SPDX-License-Identifier: GPL-3.0-only

#include "Settings.hpp"
#include <fstream>
#include <vector>

bool vsync = true;
bool showFPS = true;

std::vector<std::string> Split(std::string input, char delimiter = ' ')
{
    std::vector<std::string> output;
    output.push_back("");
    int index = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] == delimiter)
        {
            index++;
            output.push_back("");
            continue;
        }
        output[index] += input[i];
    }
    return output;
}

void Save()
{
    // Read the file
    std::fstream settingsFile;
    settingsFile.open("settings.txt", std::ios::out);
    settingsFile << "vsync=" << (vsync ? "true" : "false") << '\n';
    settingsFile << "show-fps=" << (showFPS ? "true" : "false") << '\n';
    settingsFile.close();
}

void Load()
{
    // Read the file
    std::fstream settingsFile;
    settingsFile.open("settings.txt", std::ios::in);
    std::string buf, label, value;
    while (std::getline(settingsFile, buf))
    {
        label = Split(buf, '=')[0];
        value = Split(buf, '=')[1];
        if (label == "vsync") vsync = value == "true";
        if (label == "show-fps") showFPS = value == "true";
    }
    settingsFile.close();
}
