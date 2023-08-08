#include "Engine/pch.hpp"
#include "OpenGLShader.hpp"

#include "Engine/Log.hpp"
#include "Engine/Platform/OpenGL/GLHeaders.hpp"



namespace Engine
{

    OpenGLShader::OpenGLShader(const std::string& path)
    {
        ENGINE_CORE_ERROR("OpenGLShader::OpenGLShader(const std::string& path) undefined");
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



    void OpenGLShader::Use()
    {
        glUseProgram(m_shader_id);
    }



    std::shared_ptr<Shader> Shader::CreateShader(const std::string& path)
    {
        return std::make_shared<OpenGLShader>(path);
    }

    std::shared_ptr<Shader> Shader::CreateShader(const std::string& vertex_shader_src, const std::string& fragment_shader_src)
    {
        return std::make_shared<OpenGLShader>(vertex_shader_src, fragment_shader_src);
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
}
