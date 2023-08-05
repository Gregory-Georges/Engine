#include "Engine/pch.hpp"
#include "OpenGLBuffer.hpp"



namespace Engine
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(void* data, int size)
    {
        glCreateBuffers(1, &m_buffer_id);
        Bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void OpenGLVertexBuffer::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
    }



    OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, int size)
    {
        count = size / sizeof(unsigned int);
        glCreateBuffers(1, &m_buffer_id);
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void OpenGLIndexBuffer::Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
    }






    std::unique_ptr<VertexBuffer> VertexBuffer::Create(void* data, int size)
    {
        return std::make_unique<OpenGLVertexBuffer>(data, size);
    }

    std::unique_ptr<IndexBuffer> IndexBuffer::Create(unsigned int* data, int size)
    {
        return std::make_unique<OpenGLIndexBuffer>(data, size);
    }
}
