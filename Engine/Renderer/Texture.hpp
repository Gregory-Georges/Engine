#ifndef TEXTURE_HPP_INCLUDED
#define TEXTURE_HPP_INCLUDED

#include <string>

#include "Engine/Core.hpp"



namespace Engine
{
    class Texture
    {
    public:

        Texture() = default;
        virtual ~Texture() = default;

        virtual int GetWidth() = 0;
        virtual int GetHeight() = 0;

        virtual void Bind(int slot) = 0;
    };



    class Texture2D : public Texture
    {
    public:

        Texture2D() = default;
        virtual ~Texture2D() = default;

        static Ref<Texture2D> Create(const std::string& path);
    };
}



#endif // TEXTURE_HPP_INCLUDED
