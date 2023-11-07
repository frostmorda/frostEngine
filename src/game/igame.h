#ifndef SRC_IGAME_H_
#define SRC_IGAME_H_

#include "game_object.h"
#include <unordered_map>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum class GameState
{
    GAME_ACTIVE,
    GAME_MENU,
    GAME_PAUSE,
    GAME_WIN,
    GAME_LOSE
};
const unsigned int kDefaultHeight = 600;
const unsigned int kDefaultWidgth = 800;
const std::string kDefaultWindowName = "Default Window";
class IGame
{
public:
    IGame(const unsigned int width, const unsigned int height, const std::string &window_name);
    IGame();
    virtual ~IGame();
    virtual void Initialization() = 0;
    virtual void ProcessInpud() = 0;
    virtual void Update(float delta_time) = 0;
    virtual void Render() = 0;
    GLFWwindow *GetWindow() { return window_; }

private:
    unsigned int width_;
    unsigned int height_;
    GameState state_;
    bool Keys[1024];
    std::unordered_map<std::string, std::shared_ptr<GameObject>> game_objects_;
    GLFWwindow *window_;
};
#endif // SRC_IGAME_H_