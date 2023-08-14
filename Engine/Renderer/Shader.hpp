#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED

#include <string>
#include "glm/glm.hpp"



namespace Engine
{
    class Shader
    {
    public:

        virtual ~Shader() {}

        static std::shared_ptr<Shader> CreateShader(const std::string& path);
        static std::shared_ptr<Shader> CreateShader(const std::string& vertex_shader_src, const std::string& fragment_shader_src);

        virtual void Bind() = 0;

    protected:

        Shader() {}
    };
}



#endif // SHADER_HPP_INCLUDED
