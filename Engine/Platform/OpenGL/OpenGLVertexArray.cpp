#include "OpenGLVertexArray.hpp"



namespace Engine
{
    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &id);
    }



    void OpenGLVertexArray::Bind()
    {
        glBindVertexArray(id);
    }
    void OpenGLVertexArray::Unbind()
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(std::shared_ptr<VertexBuffer> buffer)
    {
        glBindVertexArray(id);
        buffer->Bind();
        m_vertex_buffers.push_back(buffer);

    }
    void OpenGLVertexArray::SetIndexBuffer(std::shared_ptr<IndexBuffer> buffer)
    {
        glBindVertexArray(id);
        buffer->Bind();
        m_index_buffer = buffer;
    }

    int OpenGLVertexArray::GetCount()
    {
        return m_index_buffer->GetCount();
    }



    std::shared_ptr<VertexArray> VertexArray::Create()
    {
        return std::make_shared<OpenGLVertexArray>();
    }
}
