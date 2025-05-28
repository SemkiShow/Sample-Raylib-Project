#include <string>
#include <vector>
#include <fstream>

class Settings
{
    public:
        void Save(std::string fileName);
        void Load(std::string fileName);
        bool verticalSync = true;
        bool showFPS = true;
};
extern Settings settings;
