#ifndef RENDERER_HPP_INCLUDED
#define RENDERER_HPP_INCLUDED

#include "Engine/Renderer/RendererAPI.hpp"
#include "Engine/Renderer/VertexArray.hpp"

#include "Engine/Renderer/Shader.hpp"
#include "Engine/Renderer/OrthographicCamera.hpp"



namespace Engine
{
    class Renderer
    {
    public:
        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

        static void Begin();
        static void Begin(OrthographicCamera& camera);
        static void End();

        static void Submit(const std::shared_ptr<Shader>& shd, const std::shared_ptr<VertexArray>& va, glm::mat4 model_mat);

    private:

        struct SceneData
        {
            glm::mat4 viewproj_mat;
        };

        static SceneData* m_SceneData;
    };
}



#endif // RENDERER_HPP_INCLUDED
