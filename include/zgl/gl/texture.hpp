#include <zgl/render/texture.hpp>

namespace GL
{
    class Texture2D : public ZG::Texture2D
    {
        public:
            Texture2D();
            virtual ~Texture2D(); 

            virtual bool BindTexture() override;

            virtual void SetImage(int width, int height, unsigned char *data) override; 

    };

    class TextureArray : public ZG::TextureArray
    {
        public: 
            TextureArray(int width, int height, int depth);
            virtual ~TextureArray();

            virtual bool BindTexture() override; 

            virtual void SetImage(int x, int y, int z, int width, int height, int depth, void *data) override;

    };
}