#ifndef OPENGLSHADER_HPP
#define OPENGLSHADER_HPP

#include "Engine/Renderer/Shader.hpp"

#include <string>
#include <unordered_map>



namespace Engine
{

    class OpenGLShader : public Shader
    {
        public:

            OpenGLShader(const std::string& path);
            OpenGLShader(const std::string& vertex_shader_src, const std::string& fragment_shader_src);
            ~OpenGLShader();

            void Bind() override;

            void UploadUniformInt(int uni, std::string name);
            void UploadUniformFloat(float uni, std::string name);
            void UploadUniformFloat2(const glm::vec2 vec, std::string name);
            void UploadUniformFloat3(const glm::vec3& vec, std::string name);
            void UploadUniformFloat4(const glm::vec4& vec, std::string name);
            void UploadUniformMat3(const glm::mat3& mat, std::string name);
            void UploadUniformMat4(const glm::mat4& mat, std::string name);



        private:

            unsigned int m_shader_id;
            unsigned int CompileSource(const std::string& src, int shader_type);
            std::string ReadFile(const std::string& path);
            std::unordered_map<GLenum, std::string> Preprocess(const std::string& file_str);
    };

}

#endif // OPENGLSHADER_HPP
