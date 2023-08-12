#include "Engine/pch.hpp"
#include "Renderer.hpp"

#include "Engine/Renderer/RenderCommand.hpp"



namespace Engine
{
    Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;

    RendererAPI::API Renderer::GetAPI()
    {
        return RendererAPI::GetAPI();
    }



    void Renderer::Begin(OrthographicCamera& camera)
    {
        m_SceneData->viewproj_mat = camera.GetViewProjMatrix();
    }

    void Renderer::End()
    {

    }

    void Renderer::Submit(const std::shared_ptr<Shader>& shd, const std::shared_ptr<VertexArray>& va)
    {
        shd->Use();
        shd->UploadUniformMat4(m_SceneData->viewproj_mat, "u_viewprojmat");

        va->Bind();
        RenderCommand::DrawIndexed(va);
    }
}
