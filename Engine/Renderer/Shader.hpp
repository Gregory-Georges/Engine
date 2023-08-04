#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED

#include <string>



namespace Engine
{
    class Shader
    {
    public:

        virtual ~Shader() = default;

        std::unique_ptr<Shader> CreateShader(const std::string& path);
        std::unique_ptr<Shader> CreateShader(const std::string& vertex_shader_src, const std::string& fragment_shader_src);

        virtual void Use();



    protected:

        Shader() = default;
    };
}



#endif // SHADER_HPP_INCLUDED
