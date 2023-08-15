#include "Engine/pch.hpp"
#include "OpenGLTexture2D.hpp"

#include "Engine/Log.hpp"

#include "Dependencies/stb/stb_image.h"



namespace Engine
{
    OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
    {
        //Load image
        int sizex, sizey, channels;
        unsigned char* image = stbi_load(path.c_str(), &sizex, &sizey, &channels, STBI_rgb);
        if(image = NULL)
            ENGINE_CORE_ERROR("Engine could not load image at " + path);

        //Create texture
        glCreateTextures(GL_TEXTURE_2D, 1, &m_textureID);
        glBindTexture(GL_TEXTURE_2D, m_textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sizex, sizey, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

        //Parameterize texture
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glGenerateMipmap(GL_TEXTURE_2D);

        //Unload useless data
        stbi_image_free(image);
    }

    void OpenGLTexture2D::Bind(int slot)
    {

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
