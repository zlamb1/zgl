#include <glad/glad.h>

#include <zgl/ref.hpp>

#include <zgl/gl/debug.hpp>
#include <zgl/gl/shader.hpp>
#include <zgl/gl/render.hpp>
#include <zgl/gl/texture.hpp>

#include <zgl/render/texture.hpp>

namespace GL
{
    void RenderCore::SetViewport(int x, int y, int width, int height)
    {
        GLCall(glViewport(x, y, width, height)); 
    }

    Ref<ZG::Shader> RenderCore::CreateShader(ZG::ShaderType shaderType)
    {
        return CreateRef<GL::Shader>(shaderType); 
    }

    Ref<ZG::ShaderProgram> RenderCore::CreateProgram()
    {
        return CreateRef<GL::ShaderProgram>(); 
    }

    Ref<ZG::Texture2D> RenderCore::CreateTexture2D()
    {
        return CreateRef<GL::Texture2D>(); 
    }

    Ref<ZG::TextureArray> RenderCore::CreateTextureArray(int width, int height, int depth)
    {
        return CreateRef<GL::TextureArray>(width, height, depth); 
    }
};