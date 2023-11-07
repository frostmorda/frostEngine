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
    Game g;
    ResourceManager::SetExecutablePath(argv[0]);
    ResourceManager::LoadGameModelData("cube", ResourceManager::GetExecutablePath() + "model");
    VertexBufferLayout vlo;
    BufferLayout bl{3, GL_FLOAT, GL_FALSE};
    vlo.AddBufferLayout(bl);
    ResourceManager::LoadVertexBuffer("cube", "cube");
    ResourceManager::LoadVertexArray("cube", "cube", vlo);
    ResourceManager::LoadShader("cube", ResourceManager::GetExecutablePath() + "vertex.glsl", ResourceManager::GetExecutablePath() + "fragment.glsl");
    ResourceManager::LoadGameModel("cube", "cube", "cube", "cube", glm::vec2(0, 0), glm::vec2(1, 1), 45, glm::vec3(0.3f, 0.5f, 0.7f), "modelMatrix", "color");
    auto gm = ResourceManager::GetGameModel("cube");

    while (!glfwWindowShouldClose(g.GetWindow()))
    {
        float curent_frame = glfwGetTime();
        glClearColor(0, 0, 0, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        gm->SetRotation(curent_frame);
        gm->SetSize(glm::vec2(1, 1));
        gm->SetColor(glm::vec3(0.3f, 0.5f, 0.7f));
        gm->SetPosition(glm::vec2(0, 0));
        gm->Draw();
        gm->SetSize(glm::vec2(0.5f, 0.5f));
        gm->SetColor(glm::vec3(0.6f, 0.2f, 0.7f));
        gm->SetPosition(glm::vec2(0.5, 0.5));
        gm->Draw();
        glfwSwapBuffers(g.GetWindow());
        glfwPollEvents();
    }
    return 0;
}