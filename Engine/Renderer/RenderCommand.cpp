#include "Engine/pch.hpp"
#include "RenderCommand.hpp"
#include "Engine/Renderer/RendererAPI.hpp"
#include "Engine/Platform/OpenGL/OpenGLRendererAPI.hpp"



namespace Engine
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();


    void RenderCommand::SetClearColor(const glm::vec4& color)
    {
        s_RendererAPI->SetClearColor(color);
    }

    void RenderCommand::Clear()
    {
        s_RendererAPI->Clear();
    }



    void RenderCommand::DrawIndexed(const std::shared_ptr<VertexArray>& va)
    {
        s_RendererAPI->DrawIndexed(va);
    }
}
