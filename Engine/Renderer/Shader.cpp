#include "Engine/Renderer/Shader.hpp"
#include "Engine/Log.hpp"



namespace Engine
{
    void ShaderLibrary::Add(const Ref<Shader>& shd, const std::string& name)
    {
        ENGINE_CORE_ASSERT(m_loadedShaders.find(name) == m_loadedShaders.end(), "Shader " + name + " is already in the loaded shader list")
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
        Add(shd, name);

        return shd;
   }



    Ref<Shader> ShaderLibrary::Get(const std::string& name)
    {
        ENGINE_CORE_ASSERT(m_loadedShaders.find(name) != m_loadedShaders.end(), std::string("Shader name " + name + " is not in the loaded shader list"));
        return m_loadedShaders[name];
    }
}
