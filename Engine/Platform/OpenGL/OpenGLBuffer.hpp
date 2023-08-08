#ifndef OPENGLBUFFER_HPP
#define OPENGLBUFFER_HPP

#include "Engine/Renderer/Buffer.hpp"



namespace Engine
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(void* data, int size);
        void Bind() override;
        void SetLayout(const BufferLayout& buffer_layout) override;

    private:
        unsigned int m_buffer_id;
        BufferLayout m_layout;
    };



    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(unsigned int* data, int size);
        void Bind() override;

    private:
        unsigned int m_buffer_id;
        unsigned int count;
    };
}



#endif // OPENGLBUFFER_HPP
