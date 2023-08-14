#include "Engine/pch.hpp"
#include "Renderer.hpp"

#include "Engine/Renderer/RenderCommand.hpp"

#include "Engine/Platform/OpenGL/OpenGLShader.hpp"



namespace Engine
{
    Renderer::SceneData* Renderer::m_SceneData = new Renderer::SceneData;



    void Renderer::Begin(OrthographicCamera& camera)
    {
        m_SceneData->viewproj_mat = camera.GetViewProjMatrix();
    }

    void Renderer::End()
    {

    }

    void Renderer::Submit(const std::shared_ptr<Shader>& shd, const std::shared_ptr<VertexArray>& va, glm::mat4 model_mat)
    {
        shd->Bind();
        std::dynamic_pointer_cast<OpenGLShader>(shd)->UploadUniformMat4(m_SceneData->viewproj_mat, "u_viewprojmat");
        std::dynamic_pointer_cast<OpenGLShader>(shd)->UploadUniformMat4(model_mat, "u_modelmat");

        va->Bind();
        RenderCommand::DrawIndexed(va);
    }
}
