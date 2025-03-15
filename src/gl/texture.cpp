#include <glad/glad.h>

#include <zgl/gl/texture.hpp>

#include <zgl/render/texture.hpp>

namespace GL
{
    Texture2D::Texture2D() : ZG::Texture2D()
    {
        glGenTextures(1, &m_Handle);
    }

    Texture2D::~Texture2D()
    {
        glDeleteTextures(1, &m_Handle);
    }

    bool Texture2D::BindTexture()
    {
        glBindTexture(GL_TEXTURE_2D, m_Handle); 
        return true;
    }

    void Texture2D::SetImage(int width, int height, unsigned char *data)
    {
        BindTexture();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    TextureArray::TextureArray(int width, int height, int depth) : ZG::TextureArray(width, height, depth)
    {
        glGenTextures(1, &m_Handle); 
        glBindTexture(GL_TEXTURE_2D_ARRAY, m_Handle); 
        glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, GL_RGBA8, width, height, depth);;
    }

    TextureArray::~TextureArray()
    {
        glDeleteTextures(1, &m_Handle);
    }

    bool TextureArray::BindTexture()
    {
        glBindTexture(GL_TEXTURE_2D_ARRAY, m_Handle); 
        return true;
    }

    void TextureArray::SetImage(int x, int y, int z, int width, int height, int depth, void *data)
    {
        BindTexture(); 

        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        if (z >= m_HighestDepth)
            m_HighestDepth = z + 1;

        glTextureSubImage3D(m_Handle, 0, x, y, z, width, height, depth, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }

};

