#ifndef SRC_RESOURCE_MANAGER_H_
#define SRC_RESOURCE_MANAGER_H_

#include <unordered_map>
#include <memory>
#include <vector>

#include "shader.h"
#include "texture.h"

class ResourceManager
{
public:
    ResourceManager() = delete;
    static void LoadShader(const std::string &shader_name, const std::string &vertex_shader_source_file_path, const std::string &fragment_shader_source_file_path);
    static void LoadShader(const std::string &shader_name, Shader shader);
    static std::shared_ptr<Shader> GetShader(const std::string &shader_name);

    static void LoadTexture(const std::string &texture_name, const std::string &path, GLuint wrap_s = GL_REPEAT, GLuint wrap_t = GL_REPEAT, GLuint min_filter = GL_LINEAR, GLuint mag_filte = GL_LINEAR);
    static void LoadTexture(const std::string &texture_name, Texture texture);
    static std::shared_ptr<Texture> GetTexture(const std::string &texture_name);

    static void SetExecutablePath(const std::string &executable_path);
    static std::string GetExecutablePath();

    static void LoadModelData(const std::string &modle_name, const std::string &path);
    static std::vector<float> GetModelData(const std::string &modle_name);

private:
    static std::unordered_map<std::string, std::shared_ptr<Shader>> shaders_;
    static std::unordered_map<std::string, std::shared_ptr<Texture>> textures_;
    static std::unordered_map<std::string, std::vector<float>> model_data_;
    static std::string executable_path_;
};
#endif // SRC_RESOURCE_MANAGER_H_