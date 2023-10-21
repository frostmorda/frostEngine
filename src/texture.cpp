#include "texture.h"
#include "stb_image.h"
#include <iostream>

Texture::Texture(std::string path, GLuint wrap_s, GLuint wrap_t, GLuint min_filter, GLuint mag_filter)
    : wrap_s_(wrap_s), wrap_t_(wrap_t), min_filter_(min_filter), mag_filter_(mag_filter)
{
    glGenTextures(1, &id_);
    int widht, height, chanel;
    unsigned char *data = stbi_load(path.c_str(), &widht, &height, &chanel, 0);
    if (data)
    {
        GLenum format;
        if (chanel == 1)
        {
            format = GL_RED;
        }
        else if (chanel == 3)
        {
            format = GL_RGB;
        }
        else if (chanel == 4)
        {
            format = GL_RGBA;
        }
        Bind();
        glTexImage2D(GL_TEXTURE_2D, 0, format, 0, widht, height, 0, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter_);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter_);
        Unbind();
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
    }
    stbi_image_free(data);
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, id_);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
