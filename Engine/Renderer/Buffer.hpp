#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <memory>

#include "Engine/Core.hpp"



namespace Engine
{
    enum class Type
    {
        FLOAT,
        VEC2_FLOAT,
        VEC3_FLOAT,
        VEC4_FLOAT,
        MAT3_FLOAT,
        MAT4_FLOAT,
        INT,
        VEC2_INT,
        VEC3_INT,
        VEC4_INT,
        MAT3_INT,
        MAT4_INT,
        BOOL,
    };

    int Sizeof_Type(Type type);
    int Numberof_Type(Type type);
    int EngineTypeToGLType(Type type);

    struct Layout
    {
        Type m_type;
        unsigned int m_size;
        bool m_normalized;

        Layout(Type type, std::string name, bool normalized = 0);
    };

    class BufferLayout
    {
    public:

        BufferLayout(std::initializer_list<Layout> layouts);
        BufferLayout();
        void ApplyLayout();

    private:

        std::vector<Layout> m_layouts;
        unsigned int m_stride_size;
    };






    class VertexBuffer
    {
    public:
        static Ref<VertexBuffer> Create(void* data, int size);

        virtual void Bind() = 0;
        virtual void SetLayout(const BufferLayout& buffer_layout) = 0;

    protected:
        VertexBuffer() {}
    };



    class IndexBuffer
    {
    public:
        static Ref<IndexBuffer> Create(unsigned int* data, int size);
        virtual int GetCount() = 0;

        virtual void Bind() = 0;

    protected:
        IndexBuffer() {}
    };
}



#endif // BUFFER_HPP
