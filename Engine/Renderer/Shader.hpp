#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED

#include <string>
#include "glm/glm.hpp"

#include "Engine/Core.hpp"



namespace Engine
{
    class Shader
    {
    public:

        virtual ~Shader() {}

        static Ref<Shader> Create(const std::string& path);
        static Ref<Shader> Create(const std::string& vertex_shader_src, const std::string& fragment_shader_src);

        virtual void Bind() = 0;

    protected:

        Shader() {}
    };
}



#endif // SHADER_HPP_INCLUDED
