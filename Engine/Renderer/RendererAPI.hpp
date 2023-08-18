#ifndef RENDERERAPI_HPP_INCLUDED
#define RENDERERAPI_HPP_INCLUDED

#include "glm/glm.hpp"
#include "Engine/Renderer/VertexArray.hpp"



namespace Engine
{
    class RendererAPI
    {
    public:
        enum class API
        {
            NONE,
            OPEN_GL
        };

    public:

        virtual ~RendererAPI() = default;

        virtual void Init() = 0;

        virtual void SetViewport(int width, int height) = 0;

        virtual void SetClearColor(const glm::vec4& color) = 0;
        virtual void Clear() = 0;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray> va) = 0;

        static API GetAPI();

    private:

        static API s_api;
    };
}



#endif // RENDERERAPI_HPP_INCLUDED
