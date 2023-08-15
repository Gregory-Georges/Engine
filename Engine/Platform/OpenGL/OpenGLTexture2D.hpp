#ifndef OPENGLTEXTURE2D_HPP
#define OPENGLTEXTURE2D_HPP

#include "Engine/Renderer/Texture.hpp"
#include "glad/glad.h"



namespace Engine
{
    class OpenGLTexture2D : public Texture2D
    {
    public:

        OpenGLTexture2D(const std::string& path);
        void Bind(int slot) override;

        int GetWidth() override;
        int GetHeight() override;

    private:

        int m_height;
        int m_width;
        unsigned int m_textureID;
    };
}



#endif // OPENGLTEXTURE2D_HPP
