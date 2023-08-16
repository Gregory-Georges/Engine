#include "Engine/pch.hpp"
#include "OpenGLTexture2D.hpp"

#include "Engine/Log.hpp"
#include "Engine/Platform/OpenGL/GLHeaders.hpp"

#include "Dependencies/stb/stb_image.h"



namespace Engine
{
    OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
    {
        stbi_set_flip_vertically_on_load(true);

        //Load image
        int sizex, sizey, channels;
        unsigned char* image = stbi_load(path.c_str(), &sizex, &sizey, &channels, 0);
        if(image == nullptr)
            ENGINE_CORE_ERROR("Engine could not load image at " + path);
        m_width = sizex;
        m_height = sizey;

        //Create texture
        glCreateTextures(GL_TEXTURE_2D, 1, &m_textureID);
        glTextureStorage2D(m_textureID, 1, channels * 1, m_width, m_height);

        //Parameterize texture
        glBindTexture(GL_TEXTURE_2D, m_textureID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTextureSubImage2D(m_textureID, 0, 0, 0, m_width, m_height, channels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, image);

        //Unload useless data
        stbi_image_free(image);
    }

    OpenGLTexture2D::~OpenGLTexture2D()
    {
        glDeleteTextures(1, &m_textureID);
    }

    void OpenGLTexture2D::Bind(int slot)
    {
        glBindTextureUnit(slot, m_textureID);
    }



    int OpenGLTexture2D::GetWidth()
    {
        return m_width;
    }

    int OpenGLTexture2D::GetHeight()
    {
        return m_height;
    }



    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        return std::make_shared<OpenGLTexture2D>(path);
    }
}
