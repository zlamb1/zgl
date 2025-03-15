#pragma once

#include <zgl/render/render.hpp>
#include <zgl/render/texture.hpp>

namespace GL
{
    class RenderCore : public ZG::RenderCore
    {
        public:
            RenderCore() = default;
            virtual ~RenderCore() = default; 

            virtual void SetViewport(int x, int y, int width, int height) override; 

            virtual Ref<ZG::Shader> CreateShader(ZG::ShaderType shaderType) override;
            virtual Ref<ZG::ShaderProgram> CreateProgram() override;

            virtual Ref<ZG::Texture2D> CreateTexture2D() override; 
            virtual Ref<ZG::TextureArray> CreateTextureArray(int width, int height, int depth) override;

    };
};