#include "Engine/pch.hpp"
#include "OpenGLShader.hpp"

#include <fstream>

#include "glm/gtc/type_ptr.hpp"

#include "Engine/Log.hpp"
#include "Engine/Platform/OpenGL/GLHeaders.hpp"



namespace Engine
{

    OpenGLShader::OpenGLShader(const std::string& path)
    {
        unsigned int vertex_shd, fragment_shd;
        m_shader_id = glCreateProgram();

        std::string shaders_str = ReadFile(path);
        std::unordered_map<GLenum, std::string> sources = Preprocess(shaders_str);

        //Extract shaders from file
        std::string& vertex_shader_src = sources[GL_VERTEX_SHADER];
        std::string& fragment_shader_src = sources[GL_FRAGMENT_SHADER];

        //Compile all and link
        vertex_shd = CompileSource(vertex_shader_src, GL_VERTEX_SHADER);
        fragment_shd = CompileSource(fragment_shader_src, GL_FRAGMENT_SHADER);
        glAttachShader(m_shader_id, vertex_shd);
        glAttachShader(m_shader_id, fragment_shd);
        glLinkProgram(m_shader_id);
        glValidateProgram(m_shader_id);

        //Check errors
        int success;
        glGetProgramiv(m_shader_id, GL_VALIDATE_STATUS, &success);
        if(success != GL_TRUE)
        {
            int log_lenght, written;
            glGetProgramiv(m_shader_id, GL_INFO_LOG_LENGTH, &log_lenght);
            std::string log(log_lenght, ' ');
            glGetProgramInfoLog(m_shader_id, log_lenght, &written, &log[0]);
            ENGINE_CORE_ERROR("Shader linking failed: " + log);
        }

        glDeleteShader(vertex_shd);
        glDeleteShader(fragment_shd);
    }

    OpenGLShader::OpenGLShader(const std::string& vertex_shader_src, const std::string& fragment_shader_src)
    {
        unsigned int vertex_shd, fragment_shd;
        m_shader_id = glCreateProgram();

        //Compile all and link
        vertex_shd = CompileSource(vertex_shader_src, GL_VERTEX_SHADER);
        fragment_shd = CompileSource(fragment_shader_src, GL_FRAGMENT_SHADER);
        glAttachShader(m_shader_id, vertex_shd);
        glAttachShader(m_shader_id, fragment_shd);
        glLinkProgram(m_shader_id);
        glValidateProgram(m_shader_id);

        //Check errors
        int success;
        glGetProgramiv(m_shader_id, GL_VALIDATE_STATUS, &success);
        if(success != GL_TRUE)
        {
            int log_lenght, written;
            glGetProgramiv(m_shader_id, GL_INFO_LOG_LENGTH, &log_lenght);
            std::string log(log_lenght, ' ');
            glGetProgramInfoLog(m_shader_id, log_lenght, &written, &log[0]);
            ENGINE_CORE_ERROR(log);
        }

        glDeleteShader(vertex_shd);
        glDeleteShader(fragment_shd);
    }



    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_shader_id);
    }



    void OpenGLShader::Bind()
    {
        glUseProgram(m_shader_id);
    }



    void OpenGLShader::UploadUniformInt(int uni, std::string name)
    {
        int uniformLocation = glGetUniformLocation(m_shader_id, name.c_str());
        glUniform1i(uniformLocation, uni);
    }
    void OpenGLShader::UploadUniformFloat(float uni, std::string name)
    {
        int uniformLocation = glGetUniformLocation(m_shader_id, name.c_str());
        glUniform1f(uniformLocation, uni);
    }
    void OpenGLShader::UploadUniformFloat2(const glm::vec2 vec, std::string name)
    {
        int uniformLocation = glGetUniformLocation(m_shader_id, name.c_str());
        glUniform2f(uniformLocation, vec.x, vec.y);
    }
    void OpenGLShader::UploadUniformFloat3(const glm::vec3& vec, std::string name)
    {
        int uniformLocation = glGetUniformLocation(m_shader_id, name.c_str());
        glUniform3fv(uniformLocation, 1, glm::value_ptr(vec));
    }
    void OpenGLShader::UploadUniformFloat4(const glm::vec4& vec, std::string name)
    {
        int uniformLocation = glGetUniformLocation(m_shader_id, name.c_str());
        glUniform4fv(uniformLocation, 1, glm::value_ptr(vec));
    }
    void OpenGLShader::UploadUniformMat3(const glm::mat3& mat, std::string name)
    {
        int uniformLocation = glGetUniformLocation(m_shader_id, name.c_str());
        glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(mat));
    }
    void OpenGLShader::UploadUniformMat4(const glm::mat4& mat, std::string name)
    {
        int uniformLocation = glGetUniformLocation(m_shader_id, name.c_str());
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(mat));
    }



    unsigned int OpenGLShader::CompileSource(const std::string& src, int shader_type)
    {
        unsigned int shader_id = glCreateShader(shader_type);
        const char* c_str[] = { src.c_str() };
        glShaderSource(shader_id, 1, c_str, NULL);
        glCompileShader(shader_id);

        //Check compilation errors
        int result;
        glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
        if( GL_FALSE == result )
        {
            if(shader_type == GL_VERTEX_SHADER)
                ENGINE_CORE_ERROR("Vertex shader source compilation failed!");
            else if(shader_type == GL_FRAGMENT_SHADER)
                ENGINE_CORE_ERROR("Fragment shader source compilation failed!");
            else
                ENGINE_CORE_ERROR("Shader source compilation failed!");

            // Get and show info log
            int log_lenght;
            glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &log_lenght);

            if( log_lenght > 0 )
            {
                std::string log(log_lenght, ' ');
                int written;
                glGetShaderInfoLog(shader_id, log_lenght, &written, &log[0]);
                ENGINE_CORE_ERROR(log);
            }
        }

        return shader_id;
    }

    std::string OpenGLShader::ReadFile(const std::string& path)
    {
        std::ifstream in(path, std::ios::in | std::ios::binary);
        std::string file_str("");

        if(!in.is_open())
        {
            ENGINE_CORE_ERROR("Shader file could not be opened: " + path);
            return file_str;
        }

        in.seekg(0, std::ios::end);
        file_str.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&file_str[0], file_str.size());
        in.close();
        return file_str;
    }

    std::unordered_map<GLenum, std::string> OpenGLShader::Preprocess(const std::string& file_str)
    {
        char* type_token = "#type ";
        size_t type_token_len = strlen(type_token);
        std::unordered_map<GLenum, std::string> shader_srcs;
        size_t pos = file_str.find(type_token, 0);

        while(pos != std::string::npos)
        {
            //Get the token
            size_t end_of_line = file_str.find_first_of("\n\r", pos);
            std::string token = file_str.substr(pos + type_token_len, end_of_line - (pos + type_token_len));

            //Check the token
            GLenum glenum_type;
            if(token == "vertex")
                glenum_type = GL_VERTEX_SHADER;
            else if(token == "fragment" | token == "pixel")
                glenum_type = GL_FRAGMENT_SHADER;
            else
                ENGINE_CORE_ERROR("Unrecongized type token : " + token);

            //Get shader text and set next pos
            size_t next_line_pos = file_str.find_first_not_of("\r\n", end_of_line);
            pos = file_str.find(type_token, next_line_pos);
            shader_srcs[glenum_type] = file_str.substr(next_line_pos, pos - next_line_pos);
        }

        return shader_srcs;
    }



    Ref<Shader> Shader::Create(const std::string& path)
    {
        return std::make_shared<OpenGLShader>(path);
    }

    Ref<Shader> Shader::Create(const std::string& vertex_shader_src, const std::string& fragment_shader_src)
    {
        return std::make_shared<OpenGLShader>(vertex_shader_src, fragment_shader_src);
    }
}
