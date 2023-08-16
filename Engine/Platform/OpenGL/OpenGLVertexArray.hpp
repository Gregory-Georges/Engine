#ifndef OPENGLVERTEXARRAY_HPP
#define OPENGLVERTEXARRAY_HPP

#include <vector>
#include <memory>

#include "Engine/Renderer/Buffer.hpp"
#include "Engine/Renderer/VertexArray.hpp"



namespace Engine
{
    class OpenGLVertexArray : public VertexArray
    {
    public:

        OpenGLVertexArray();
        ~OpenGLVertexArray();

        void Bind() override;
        void Unbind() override;

        void AddVertexBuffer(std::shared_ptr<VertexBuffer> buffer) override;
        void SetIndexBuffer(std::shared_ptr<IndexBuffer> buffer) override;

        inline int GetCount() override;



    private:

        unsigned int id;
        std::vector<std::shared_ptr<VertexBuffer>> m_vertex_buffers;
        std::shared_ptr<IndexBuffer> m_index_buffer;
    };
}

#endif // OPENGLVERTEXARRAY_HPP
