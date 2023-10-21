#include "resource_manager.h"
std::unordered_map<std::string, std::shared_ptr<Shader>> ResourceManager::Shaders;
std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::Textures;
std::string ResourceManager::executable_path_;

void ResourceManager::LoadShader(const std::string &shader_name, const std::string &vertex_shader_source_file_path, const std::string &fragment_shader_source_file_path)
{
    Shaders[shader_name] = std::make_shared<Shader>(vertex_shader_source_file_path, fragment_shader_source_file_path);
}

void ResourceManager::LoadShader(const std::string &shader_name, Shader shader)
{
    Shaders[shader_name] = std::make_shared<Shader>(std::move(shader));
}

std::shared_ptr<Shader> ResourceManager::GetShader(const std::string &shader_name)
{
    return Shaders[shader_name];
}

void ResourceManager::LoadTexture(const std::string &texture_name, const std::string &path, GLuint wrap_s, GLuint wrap_t, GLuint min_filter, GLuint mag_filte)
{
    Textures[texture_name] = std::make_shared<Texture>(path, wrap_s, wrap_t, min_filter, mag_filte);
}

void ResourceManager::LoadTexture(const std::string &texture_name, Texture texture)
{
    Textures[texture_name] = std::make_shared<Texture>(std::move(texture));
}

std::shared_ptr<Texture> ResourceManager::GetTexture(const std::string texture_name)
{
    return Textures[texture_name];
}

void ResourceManager::SetExecutablePath(const std::string &executable_path)
{
    auto found = executable_path.find_last_of("/\\");
    executable_path_ = executable_path.substr(0, found);
}

std::string ResourceManager::GetExecutablePath()
{
    return executable_path_;
}
