#include "sprite.h"
#include <glm/gtc/matrix_transform.hpp>

Sprite::Sprite(std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, std::shared_ptr<VertexArray> vertex_array, const glm::vec2 &position, const glm::vec2 &size, const float rotation, const glm::vec3 &color, const std::string &model_matrix_name, const std::string &sprite_color_name)
    : shader_(std::move(shader)), texture_(std::move(texture)), vertex_array_(std::move(vertex_array)), position_(position), size_(size), rotation_(rotation), color_(color), model_matrix_name_(model_matrix_name), sprite_color_name_(sprite_color_name)
{
}

Sprite::~Sprite()
{
}

void Sprite::Draw()
{
    shader_->Use();
    Transformation();
    // glActiveTexture(GL_TEXTURE0);
    // texture_->Bind();
    vertex_array_->Bind();
    glDrawArrays(GL_TRIANGLES, 0, vertex_array_->GetSize());
    vertex_array_->Unbind();
}

void Sprite::SetShader(std::shared_ptr<Shader> shader)
{
    shader_ = std::move(shader);
}

void Sprite::SetTexture(std::shared_ptr<Texture> texture)
{
    texture = std::move(texture);
}

void Sprite::SetVertexArray(std::shared_ptr<VertexArray> vertex_array)
{
    vertex_array_ = std::move(vertex_array);
}

void Sprite::SetPosition(const glm::vec2 &position)
{
    position_ = position_;
}

void Sprite::SetSize(const glm::vec2 &size)
{
    size_ = size;
}

void Sprite::SetRotation(const float rotation)
{
    rotation_ = rotation;
}

void Sprite::SetColor(const glm::vec3 &color)
{
    color_ = color;
}

void Sprite::Transformation()
{
    shader_->Use();
    glm::mat4 model(1.0f);
    model = glm::translate(model, glm::vec3(position_, 0.0f));
    model = glm::translate(model, glm::vec3(0.5f * position_, 0.0f));
    model = glm::rotate(model, glm::radians(rotation_), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * position_, 0.0f));
    model = scale(model, glm::vec3(size_, 1.0f));
    shader_->SetUniform(model_matrix_name_, model);
    shader_->SetUniform(sprite_color_name_, color_);
}
