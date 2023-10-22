#ifndef SRC_GAME_H_
#define SRC_GAME_H_

enum class GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_PAUSE,
    GAME_WIN,
    GAME_LOSE
};
class Game
{
public:
    Game(unsigned int width, unsigned int height);
    ~Game();
    void Initialization();
    void ProcessInpud();
    void Update(float delta_time);
    void Render();

private:
    unsigned int width_;
    unsigned int height_;
    GameState state_;
    bool Keys[1024];
};
#endif // SRC_GAME_H_
