#ifndef RENDERCOMMAND_HPP_INCLUDED
#define RENDERCOMMAND_HPP_INCLUDED

#include "glm/glm.hpp"

#include "Engine/Renderer/RendererAPI.hpp"



namespace Engine
{
    class RenderCommand
    {
    public:

        static void SetClearColor(const glm::vec4& color);
        static void Clear();
        static void DrawIndexed(const std::shared_ptr<VertexArray>& va);

    private:
        static RendererAPI* s_RendererAPI;
    };
}



#endif // RENDERCOMMAND_HPP_INCLUDED
