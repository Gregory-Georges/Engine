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
        m_layout.ApplyLayout();
    }



    void OpenGLVertexBuffer::SetLayout(const BufferLayout& buffer_layout)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
        m_layout = buffer_layout;
        m_layout.ApplyLayout();
    }



    OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, int size)
    {
        m_count = size / sizeof(unsigned int);
        glCreateBuffers(1, &m_buffer_id);
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void OpenGLIndexBuffer::Bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_buffer_id);
    }



    int OpenGLIndexBuffer::GetCount()
    {
        return m_count;
    }






    std::shared_ptr<VertexBuffer> VertexBuffer::Create(void* data, int size)
    {
        return std::make_shared<OpenGLVertexBuffer>(data, size);
    }

    std::shared_ptr<IndexBuffer> IndexBuffer::Create(unsigned int* data, int size)
    {
        return std::make_shared<OpenGLIndexBuffer>(data, size);
    }
}
