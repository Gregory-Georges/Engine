#ifndef RENDERCOMMAND_HPP_INCLUDED
#define RENDERCOMMAND_HPP_INCLUDED

#include "glm/glm.hpp"

#include "Engine/Renderer/RendererAPI.hpp"



namespace Engine
{
    class RenderCommand
    {
    public:

        static void Init() { s_RendererAPI->Init(); }

        inline static void SetViewport(int width, int height) { s_RendererAPI->SetViewport(width, height); }

        inline static void SetClearColor(const glm::vec4& color) { s_RendererAPI->SetClearColor(color); }
        inline static void Clear() { s_RendererAPI->Clear(); }
        inline static void DrawIndexed(const std::shared_ptr<VertexArray>& va) { s_RendererAPI->DrawIndexed(va); }

    private:
        static RendererAPI* s_RendererAPI;
    };
}



#endif // RENDERCOMMAND_HPP_INCLUDED
