#include "Settings.hpp"
#include "UI.hpp"

bool vsync = true;
bool showFPS = true;

std::vector<std::string> Split(std::string input, char delimiter = ' ')
{
    std::vector<std::string> output;
    output.push_back("");
    int index = 0;
    for (int i = 0; i < input.size(); i++)
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

void Save(std::string fileName)
{
    // Read the file
    std::fstream settingsFile;
    settingsFile.open(fileName, std::ios::out);
    settingsFile << "vsync=" << (vsync ? "true" : "false") << '\n';
    settingsFile << "show-fps=" << (showFPS ? "true" : "false") << '\n';
    settingsFile.close();
}

void Load(std::string fileName)
{
    // Read the file
    std::fstream settingsFile;
    settingsFile.open(fileName, std::ios::in);
    std::vector<std::string> settingsList;
    std::string buf;
    while (std::getline(settingsFile, buf))
        settingsList.push_back(buf);
    settingsFile.close();

    // Process the file
    vsync = settingsList[0].substr(6) == "true";
    showFPS = settingsList[1].substr(9) == "true";
}
