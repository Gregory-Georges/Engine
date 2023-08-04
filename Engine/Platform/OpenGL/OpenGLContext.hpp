#ifndef OPENGLCONTEXT_HPP
#define OPENGLCONTEXT_HPP

#include "Engine/Renderer/GraphicsContext.hpp"


namespace Engine
{

    class OpenGLContext : public GraphicsContext
    {
        public:

            OpenGLContext() = default;

            void Init(void* window) override;
            void SwapBuffers() override;

        private:

            void* m_window;
    };

}



#endif // OPENGLCONTEXT_HPP
