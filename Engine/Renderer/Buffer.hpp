#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <memory>



namespace Engine
{
    class VertexBuffer
    {
    public:
        static std::unique_ptr<VertexBuffer> Create(void* data, int size);

        virtual void Bind() = 0;

    protected:
        VertexBuffer() {}
    };



    class IndexBuffer
    {
    public:
        static std::unique_ptr<IndexBuffer> Create(unsigned int* data, int size);

        virtual void Bind() = 0;

    protected:
        IndexBuffer() {}
    };
}



#endif // BUFFER_HPP
