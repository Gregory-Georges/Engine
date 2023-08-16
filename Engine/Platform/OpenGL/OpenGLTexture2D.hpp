#ifndef OPENGLTEXTURE2D_HPP
#define OPENGLTEXTURE2D_HPP

#include "Engine/Renderer/Texture.hpp"



namespace Engine
{
    class OpenGLTexture2D : public Texture2D
    {
    public:

        OpenGLTexture2D(const std::string& path);
        ~OpenGLTexture2D();
        void Bind(int slot = 0) override;

        int GetWidth() override;
        int GetHeight() override;

    private:

        int m_height;
        int m_width;
        unsigned int m_textureID;
    };
}



#endif // OPENGLTEXTURE2D_HPP
