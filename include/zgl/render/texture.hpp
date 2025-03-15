#pragma once

#include <zgl/resource.hpp>

namespace ZG
{
    enum class TextureType : int
    {
        TEXTURE2D,
        TEXTURE2DARRAY,
        TEXTURE3D
    };

    class Texture : public ResourceHandle<unsigned int> 
    {
        public:
            Texture(TextureType textureType) : m_TextureType(textureType) {}
            virtual ~Texture() = default; 

            virtual bool BindTexture() = 0;

            TextureType GetTextureType() const { return m_TextureType; }

        protected:
            TextureType m_TextureType; 

    };

    class Texture2D : public Texture
    {
        public:
            Texture2D() : Texture(TextureType::TEXTURE2D) 
            {
            }

            virtual ~Texture2D() = default; 

            virtual void SetImage(int width, int height, unsigned char *data) = 0; 
    };
    
    class TextureArray : public Texture
    {
        public:
            TextureArray(int width, int height, int depth) : Texture(TextureType::TEXTURE2DARRAY)
            {
                m_Width = width;
                m_Height = height;
                m_Depth = depth;
                m_HighestDepth = 0; 
            }

            virtual ~TextureArray() = default; 

            virtual bool AddImage(void *data)
            {
                return AddImage(0, 0, m_Width, m_Height, data); 
            }

            virtual bool AddImage(int x, int y, int width, int height, void *data)
            {
                if (m_HighestDepth >= m_Depth)
                    return false;
                SetImage(x, y, m_HighestDepth, width, height, 1, data);
                return true; 
            }

            virtual void SetImage(int x, int y, int z, int width, int height, int depth, void *data) = 0;
        
        protected: 
            int m_Width;
            int m_Height;
            int m_Depth;
            int m_HighestDepth;

    };
};