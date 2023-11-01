#include <iostream>
#include "game/igame.h"
#include "engine/resource_manager.h"

class Game : public IGame
{
public:
    Game() : IGame() {}
    ~Game() {}
    void Initialization(){};
    void ProcessInpud(){};
    void Update(float delta_time){};
    void Render(){};
};
int main(int argc, char **argv)
{
    ResourceManager::SetExecutablePath(argv[0]);
    ResourceManager::LoadModelData("cube", ResourceManager::GetExecutablePath() + "model");
    auto data = ResourceManager::GetModelData("cube");
    for (auto &val : data)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}