#ifndef VERTEXARRAY_HPP_INCLUDED
#define VERTEXARRAY_HPP_INCLUDED

#include "Engine/Renderer/Buffer.hpp"



namespace Engine
{
    class VertexArray
    {
    public:

        virtual void Bind() = 0;
        virtual void Unbind() = 0;

        virtual void AddVertexBuffer(std::shared_ptr<VertexBuffer> vertex_buffer) = 0;
        virtual void SetIndexBuffer(std::shared_ptr<IndexBuffer> index_buffer) = 0;

        virtual int GetCount() = 0;

        static std::shared_ptr<VertexArray> Create();
    };
}



#endif // VERTEXARRAY_HPP_INCLUDED
