#include <fstream>
#include <sstream>
#include "resource_manager.h"

std::unordered_map<std::string, std::shared_ptr<Shader>> ResourceManager::shaders_;
std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::textures_;
std::unordered_map<std::string, std::vector<float>> ResourceManager::model_data_;
std::string ResourceManager::executable_path_;

void ResourceManager::LoadShader(const std::string &shader_name, const std::string &vertex_shader_source_file_path, const std::string &fragment_shader_source_file_path)
{
    shaders_[shader_name] = std::make_shared<Shader>(vertex_shader_source_file_path, fragment_shader_source_file_path);
}

void ResourceManager::LoadShader(const std::string &shader_name, Shader shader)
{
    shaders_[shader_name] = std::make_shared<Shader>(std::move(shader));
}

std::shared_ptr<Shader> ResourceManager::GetShader(const std::string &shader_name)
{
    return shaders_[shader_name];
}

void ResourceManager::LoadTexture(const std::string &texture_name, const std::string &path, GLuint wrap_s, GLuint wrap_t, GLuint min_filter, GLuint mag_filte)
{
    textures_[texture_name] = std::make_shared<Texture>(path, wrap_s, wrap_t, min_filter, mag_filte);
}

void ResourceManager::LoadTexture(const std::string &texture_name, Texture texture)
{
    textures_[texture_name] = std::make_shared<Texture>(std::move(texture));
}

std::shared_ptr<Texture> ResourceManager::GetTexture(const std::string &texture_name)
{
    return textures_[texture_name];
}

void ResourceManager::SetExecutablePath(const std::string &executable_path)
{
    auto found = executable_path.find_last_of("/\\");
    executable_path_ = executable_path.substr(0, found) + "\\";
}

std::string ResourceManager::GetExecutablePath()
{
    return executable_path_;
}

void ResourceManager::LoadModelData(const std::string &modle_name, const std::string &path)
{
    std::ifstream f;
    f.open(path);
    if (!f.is_open())
    {
        std::cerr << "not open!" << std::endl;
        return;
    }
    std::stringstream buffer;
    buffer << f.rdbuf();
    std::string data = buffer.str();
    size_t found = 0;
    size_t start = 0;

    while (found != std::string::npos)
    {
        std::string num = data.substr(start);
        if (isdigit(num[0]) || num[0] == '-')
        {
            float val = stof(num);
            std::cout << val << " ";
            model_data_[modle_name].push_back(val);
        }
        found = data.find_first_of(" \n", found + 1);
        start = found + 1;
    }
    auto v = model_data_[modle_name];
    // for (auto &val : v) {
    //     std::cout << val << " ";
    // }
    std::cout << std::endl;
}

std::vector<float> ResourceManager::GetModelData(const std::string &modle_name)
{
    return model_data_[modle_name];
}
