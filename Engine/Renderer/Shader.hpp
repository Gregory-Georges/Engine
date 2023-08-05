#ifndef SHADER_HPP_INCLUDED
#define SHADER_HPP_INCLUDED

#include <string>



namespace Engine
{
    class Shader
    {
    public:

        virtual ~Shader() {}

        static std::unique_ptr<Shader> CreateShader(const std::string& path);
        static std::unique_ptr<Shader> CreateShader(const std::string& vertex_shader_src, const std::string& fragment_shader_src);

        virtual void Use() = 0;



    protected:

        Shader() {}
    };
}



#endif // SHADER_HPP_INCLUDED
