#include "Buffer.hpp"

#include "../Platform/OpenGL/GLHeaders.hpp"
#include "../Log.hpp"



namespace Engine
{
    int Sizeof_Type(Type type)
    {
        switch(type)
        {
        case Type::FLOAT :              return 4;
        case Type::VEC2_FLOAT :         return 2 * 4;
        case Type::VEC3_FLOAT :         return 3 * 4;
        case Type::VEC4_FLOAT :         return 4 * 4;
        case Type::MAT3_FLOAT :         return 3 * 3 * 4;
        case Type::MAT4_FLOAT :         return 4 * 4 * 4;
        case Type::INT :                return 4;
        case Type::VEC2_INT :           return 2 * 4;
        case Type::VEC3_INT :           return 3 * 4;
        case Type::VEC4_INT :           return 4 * 4;
        case Type::MAT3_INT :           return 3 * 3 * 4;
        case Type::MAT4_INT :           return 4 * 4 * 4;
        case Type::BOOL :               return 1;
        }

        ENGINE_CORE_ERROR("Wrong type specifier in layout");
        return 0;
    }

    int NumberOf_Type(Type type)
    {
        switch(type)
        {
        case Type::FLOAT :              return 1;
        case Type::VEC2_FLOAT :         return 2 * 1;
        case Type::VEC3_FLOAT :         return 3 * 1;
        case Type::VEC4_FLOAT :         return 4 * 1;
        case Type::MAT3_FLOAT :         return 3 * 3 * 1;
        case Type::MAT4_FLOAT :         return 4 * 4 * 1;
        case Type::INT :                return 1;
        case Type::VEC2_INT :           return 2 * 1;
        case Type::VEC3_INT :           return 3 * 1;
        case Type::VEC4_INT :           return 4 * 1;
        case Type::MAT3_INT :           return 3 * 3 * 1;
        case Type::MAT4_INT :           return 4 * 4 * 1;
        case Type::BOOL :               return 1;
        }

        ENGINE_CORE_ERROR("Wrong type specifier in layout");
        return 0;
    }

    int EngineTypeToGLType(Type type)
    {
        switch(type)
        {
        case Type::FLOAT :              return GL_FLOAT;
        case Type::VEC2_FLOAT :         return GL_FLOAT;
        case Type::VEC3_FLOAT :         return GL_FLOAT;
        case Type::VEC4_FLOAT :         return GL_FLOAT;
        case Type::MAT3_FLOAT :         return GL_FLOAT;
        case Type::MAT4_FLOAT :         return GL_FLOAT;
        case Type::INT :                return GL_INT;
        case Type::VEC2_INT :           return GL_INT;
        case Type::VEC3_INT :           return GL_INT;
        case Type::VEC4_INT :           return GL_INT;
        case Type::BOOL :               return GL_BOOL;
        }

        ENGINE_CORE_ERROR("Wrong type specifier in layout");
        return 0;
    }



    Layout::Layout(Type type, std::string name, bool normalized) :
            m_type(type), m_size(Sizeof_Type(type)), m_normalized(normalized) {}

    BufferLayout::BufferLayout(std::initializer_list<Layout> layouts) :
            m_layouts(layouts), m_stride_size(0) { for(Layout& layout : m_layouts) m_stride_size += layout.m_size; }

    void BufferLayout::ApplyLayout()
    {
        int layout_size = m_layouts.size();
        int offset = 0;
        for(unsigned int i = 0; i < layout_size; ++i)
        {
            Layout& lay = m_layouts[i];
            glVertexAttribPointer(i, NumberOf_Type(lay.m_type), EngineTypeToGLType(lay.m_type), lay.m_normalized, m_stride_size, (void*)offset);
            glEnableVertexAttribArray(i);
            offset += lay.m_size;
        }
    }
}
