#ifndef GRAPHICSCONTEXT_HPP_INCLUDED
#define GRAPHICSCONTEXT_HPP_INCLUDED

#include <memory>



namespace Engine
{

    class GraphicsContext
    {
    public:

        virtual ~GraphicsContext() = default;

        virtual void Init(void* window) = 0;
        virtual void SwapBuffers() = 0;

        static std::unique_ptr<GraphicsContext> CreateContext();
    };

}



#endif // GRAPHICSCONTEXT_HPP_INCLUDED
