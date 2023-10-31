#include <iostream>
#include "game/igame.h"

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
    Game g;
    while (1)
    {
        glfwSwapBuffers(g.GetWindow());
        glfwPollEvents();
    }
    return 0;
}