#include "game_model.h"
#include <glm/gtc/matrix_transform.hpp>

GameModel::GameModel()
{
    shader_ = nullptr;
    texture_ = nullptr;
    vertex_array_ = nullptr;
}

GameModel::GameModel(Shader *shader, Texture *texture, VertexArray *vertex_array, const glm::vec3 &position, const glm::vec3 &size, const float rotation, const glm::vec3 &color, const std::string &model_matrix_name, const std::string &game_model_color_name, const std::string &texture_name)
    : shader_(shader), texture_(texture), vertex_array_(vertex_array), position_(position), size_(size), rotation_(rotation), color_(color), model_matrix_name_(model_matrix_name), game_model_color_name_(game_model_color_name), texture_name_(texture_name)
{
}

GameModel::GameModel(GameModel &&other)
{
    shader_ = other.shader_;
    texture_ = other.texture_;
    vertex_array_ = other.vertex_array_;
    position_ = other.position_;
    size_ = other.position_;
    rotation_ = other.rotation_;
    color_ = other.color_;
    model_matrix_name_ = other.model_matrix_name_;
    game_model_color_name_ = other.game_model_color_name_;
    texture_name_ = other.texture_name_;

    other.shader_ = nullptr;
    other.texture_ = nullptr;
    other.vertex_array_ = nullptr;
}

GameModel &GameModel::operator=(GameModel &&other)
{
    shader_ = other.shader_;
    texture_ = other.texture_;
    vertex_array_ = other.vertex_array_;
    position_ = other.position_;
    size_ = other.position_;
    rotation_ = other.rotation_;
    color_ = other.color_;
    model_matrix_name_ = other.model_matrix_name_;
    game_model_color_name_ = other.game_model_color_name_;
    texture_name_ = other.texture_name_;

    other.shader_ = nullptr;
    other.texture_ = nullptr;
    other.vertex_array_ = nullptr;
    return *this;
}

GameModel::~GameModel()
{
}

void GameModel::Draw()
{
    shader_->Use();
    shader_->SetUniform(texture_name_, 0);
    Transformation();
    if (texture_)
    {
        glActiveTexture(GL_TEXTURE0);
        texture_->Bind();
    }
    vertex_array_->Bind();
    glDrawArrays(GL_TRIANGLES, 0, vertex_array_->GetSize());
    vertex_array_->Unbind();
}

void GameModel::SetShader(Shader *shader)
{
    shader_ = shader;
}

void GameModel::SetTexture(Texture *texture)
{
    texture_ = texture;
}

void GameModel::SetVertexArray(VertexArray *vertex_array)
{
    vertex_array_ = vertex_array;
}

void GameModel::SetPosition(const glm::vec3 &position)
{
    position_ = position;
}

void GameModel::SetSize(const glm::vec3 &size)
{
    size_ = size;
}

void GameModel::SetRotation(const float rotation)
{
    rotation_ = rotation;
}

void GameModel::SetColor(const glm::vec3 &color)
{
    color_ = color;
}

void GameModel::Transformation()
{
    shader_->Use();
    glm::mat4 model_matrix(1.0f);
    model_matrix = glm::translate(model_matrix, position_);
    model_matrix = glm::translate(model_matrix, 0.5f * position_);
    model_matrix = glm::rotate(model_matrix, glm::radians(rotation_), glm::vec3(0.0f, 0.0f, 1.0f));
    model_matrix = glm::translate(model_matrix, -0.5f * position_);
    model_matrix = scale(model_matrix, size_);
    shader_->SetUniform(model_matrix_name_, model_matrix);
    shader_->SetUniform(game_model_color_name_, color_);
}
