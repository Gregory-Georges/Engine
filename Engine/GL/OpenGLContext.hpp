#ifndef OPENGLCONTEXT_HPP
#define OPENGLCONTEXT_HPP

#include "../GraphicsContext.hpp"


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
