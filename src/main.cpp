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
    ResourceManager::LoadModelData("cube", ResourceManager::GetExecutablePath() + "model");
    auto data = ResourceManager::GetModelData("cube");
    VertexBuffer vb(data.data(), data.size());
    VertexBufferLayout vlo;
    BufferLayout bl{3, GL_FLOAT, GL_FALSE};
    vlo.AddBufferLayout(bl);
    VertexArray VAO(vb, vlo);
    ResourceManager::LoadShader("Def", ResourceManager::GetExecutablePath() + "vertex.glsl", ResourceManager::GetExecutablePath() + "fragment.glsl");
    auto shader = ResourceManager::GetShader("Def");
    std::shared_ptr<VertexArray> va = std::make_shared<VertexArray>(std::move(VAO));
    Sprite s(shader, nullptr, va, glm::vec2(0, 0), glm::vec2(1, 1), 70, glm::vec3(0.0, 0.9, 0.5), "modelMatrix", "color");

    while (!glfwWindowShouldClose(g.GetWindow()))
    {
        glClearColor(0, 0, 0, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shader->Use();
        VAO.Bind();
        s.Draw();
        glfwSwapBuffers(g.GetWindow());
        glfwPollEvents();
    }
    return 0;
}