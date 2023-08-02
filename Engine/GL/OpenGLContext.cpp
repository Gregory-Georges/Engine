#include "../pch.hpp"
#include "OpenGLContext.hpp"



namespace Engine
{
        void OpenGLContext::Init(void* window)
        {
            m_window = window;
            glfwMakeContextCurrent((GLFWwindow*)window);
        }



        void OpenGLContext::SwapBuffers()
        {
            glfwSwapBuffers((GLFWwindow*)m_window);
        }



        std::unique_ptr<GraphicsContext> GraphicsContext::CreateContext()
        {
            return std::make_unique<OpenGLContext>();
        }
}
