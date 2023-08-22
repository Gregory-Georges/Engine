#include "Engine/Renderer/Shader.hpp"
#include "Engine/Log.hpp"



namespace Engine
{
    void ShaderLibrary::Add(const Ref<Shader>& shd, const std::string& name)
    {
        m_loadedShaders[name] = shd;
    }

    Ref<Shader> ShaderLibrary::Load(const std::string& path)
    {
        //Load the shader
        Ref<Shader> shd = Shader::Create(path);

        //Extract the name
        size_t pos = path.find_last_of("/\\");
        size_t stp = path.rfind('.');

        //Error handling
        if(pos == std::string::npos)
            pos = 0;
        if(stp == std::string::npos)
            stp = path.length();

        //Put in dictionnary
        std::string name = path.substr(pos + 1, stp - pos - 1);
        m_loadedShaders[name] = shd;

        return shd;
   }



    Ref<Shader> ShaderLibrary::Get(const std::string& name)
    {
        if(m_loadedShaders.find(name) == m_loadedShaders.end())
            ENGINE_CORE_ERROR("Shader " + name + " is requested but not loaded");

        return m_loadedShaders[name];
    }
}
