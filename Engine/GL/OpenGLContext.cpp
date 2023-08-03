#include "../pch.hpp"
#include "OpenGLContext.hpp"
#include "../Log.hpp"



namespace Engine
{
        void OpenGLContext::Init(void* window)
        {
            //Make an opengl context
            m_window = window;
            glfwMakeContextCurrent((GLFWwindow*)window);

            //Init glad
            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                ENGINE_CORE_ERROR("Could not initialize GLAD");

            //Print info on the screen
            std::cout << "Vendor : " << glGetString(GL_VENDOR) << "\n";
            std::cout << "Renderer : " << glGetString(GL_RENDERER) << "\n";
            std::cout << "Version : " << glGetString(GL_VERSION) << "\n";
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
