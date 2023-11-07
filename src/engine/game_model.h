#ifndef SRC_GAME_MODEL_H_
#define SRC_GAME_MODEL_H_

#include <memory>
#include "shader.h"
#include "texture.h"
#include "vertex_array.h"

class GameModel
{
public:
    GameModel();
    GameModel(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, std::shared_ptr<VertexArray> vertex_array, const glm::vec2 &position, const glm::vec2 &size, const float rotation, const glm::vec3 &color, const std::string &model_matrix_name, const std::string &game_model_color_name);
    GameModel(const GameModel &other) = delete;
    GameModel &operator=(const GameModel &other) = delete;
    GameModel(GameModel &&other);
    GameModel &operator=(GameModel &&other);
    ~GameModel();
    void Draw();
    void SetShader(std::shared_ptr<Shader> shader);
    void SetTexture(std::shared_ptr<Texture> texture);
    void SetVertexArray(std::shared_ptr<VertexArray> vertex_array);
    void SetPosition(const glm::vec2 &position);
    void SetSize(const glm::vec2 &size);
    void SetRotation(const float rotation);
    void SetColor(const glm::vec3 &color);

private:
    std::shared_ptr<Shader> shader_;
    std::shared_ptr<Texture> texture_;
    std::shared_ptr<VertexArray> vertex_array_;
    glm::vec2 position_;
    glm::vec2 size_;
    float rotation_;
    glm::vec3 color_;
    std::string model_matrix_name_;
    std::string game_model_color_name_;
    void Transformation();
};
#endif // SRC_GAME_MODEL_H_