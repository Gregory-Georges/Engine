#include "Engine/pch.hpp"
#include "Renderer.hpp"

#include "Engine/Renderer/RenderCommand.hpp"



namespace Engine
{
    RendererAPI::API Renderer::GetAPI()
    {
        return RendererAPI::GetAPI();
    }



    void Renderer::Begin()
    {

    }

    void Renderer::End()
    {

    }

    void Renderer::Submit(const std::shared_ptr<VertexArray>& va)
    {
        RenderCommand::DrawIndexed(va);
    }
}
