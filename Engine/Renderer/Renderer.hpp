#ifndef RENDERER_HPP_INCLUDED
#define RENDERER_HPP_INCLUDED

#include "Engine/Renderer/RendererAPI.hpp"
#include "Engine/Renderer/VertexArray.hpp"



namespace Engine
{
    class Renderer
    {
    public:
        static RendererAPI::API GetAPI();

        static void Begin();
        static void End();

        static void Submit(const std::shared_ptr<VertexArray>& va);
    };
}



#endif // RENDERER_HPP_INCLUDED
