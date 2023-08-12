#ifndef OPENGLSHADER_HPP
#define OPENGLSHADER_HPP

#include "Engine/Renderer/Shader.hpp"



namespace Engine
{

    class OpenGLShader : public Shader
    {
        public:

            OpenGLShader(const std::string& path);
            OpenGLShader(const std::string& vertex_shader_src, const std::string& fragment_shader_src);
            ~OpenGLShader();

            void Use() override;
            void UploadUniformMat4(const glm::mat4& matrix, std::string name) override;



        private:

            unsigned int m_shader_id;
            unsigned int CompileSource(const std::string& src, int shader_type);
    };

}

#endif // OPENGLSHADER_HPP
