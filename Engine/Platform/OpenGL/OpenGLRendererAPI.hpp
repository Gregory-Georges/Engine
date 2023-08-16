#ifndef OPENGLRENDERERAPI_HPP
#define OPENGLRENDERERAPI_HPP

#include "Engine/Renderer/RendererAPI.hpp"



namespace Engine
{
    class OpenGLRendererAPI : public RendererAPI
    {
        void Init() override;
        void SetClearColor(const glm::vec4& color) override;
        void Clear() override;

        void DrawIndexed(const std::shared_ptr<VertexArray> va) override;
    };
}



#endif // OPENGLRENDERERAPI_HPP
