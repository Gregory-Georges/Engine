#include "Engine/pch.hpp"
#include "OpenGLRendererAPI.hpp"



namespace Engine
{
    void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
    {
        glClearColor(color.x, color.y, color.z, color.w);
    }

    void OpenGLRendererAPI::Clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray> va)
    {
        glDrawElements(GL_TRIANGLES, va->GetCount(), GL_UNSIGNED_INT, nullptr);
    }
}
