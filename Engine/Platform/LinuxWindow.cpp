#include "../pch.hpp"
#include "LinuxWindow.hpp"

#include "../GL/GLHeaders.hpp"
#include "../Application.hpp"

#include "../Events/ApplicationEvent.hpp"
#include "../Events/KeyEvent.hpp"
#include "../Events/MouseEvent.hpp"
#include "../Log.hpp"



int Engine::LinuxWindow::window_count = 0;



Engine::LinuxWindow::LinuxWindow(const WindowProps& wp)
{
    Init(wp);
    ++window_count;
}

Engine::LinuxWindow::~LinuxWindow()
{
    glfwDestroyWindow(m_Window);
    --window_count;

    if(window_count == 0)
        Shutdown();
}



void Engine::LinuxWindow::OnUpdate()
{
    m_context->SwapBuffers();
}



unsigned int Engine::LinuxWindow::GetWidth()
{
    return m_data.Width;
}

unsigned int Engine::LinuxWindow::GetHeight()
{
    return m_data.Height;
}

void Engine::LinuxWindow::SetVSync(bool enabled)
{
    glfwSwapInterval(int(enabled));
    m_data.VSync = enabled;
}

bool Engine::LinuxWindow::IsVSync()
{
    return m_data.VSync;
}



//More stuff
void* Engine::LinuxWindow::GetNativeWindow()
{
    return m_Window;
}



void Engine::LinuxWindow::Init(const WindowProps& wp)
{
    //Initialize if necessary
    if(window_count == 0 && glfwInit() != GLFW_TRUE)
        ENGINE_CORE_ERROR("Could not initialize GLFW upon linux window creation");

    //Set data
    m_data.Title = wp.title;
    m_data.Width = wp.width;
    m_data.Height = wp.height;

    //Create window
    m_Window = glfwCreateWindow(m_data.Width, m_data.Height, m_data.Title.c_str(), NULL, NULL);
    if(m_Window == nullptr)
        ENGINE_CORE_ERROR("Could not create linux window");
    glfwSetWindowUserPointer(m_Window, &m_data);

    m_context = GraphicsContext::CreateContext();
    m_context->Init(m_Window);

    //Other parameters
    glViewport(0, 0, wp.width, wp.height);
    SetVSync(true);



    //Set window callback functions

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
    {
        WindowData& Data = *(WindowData*)glfwGetWindowUserPointer(window);

        Data.Width = width;
        Data.Height = height;
        glViewport(0, 0, width, height);

        ENGINE_SEND_EVENT(WindowResizeEvent, width, height);
        ENGINE_INFO("Window size callback occurred");
    });

    glfwSetWindowPosCallback(m_Window, [](GLFWwindow* window, int new_x, int new_y)
    {
        ENGINE_SEND_EVENT(WindowMovedEvent, new_x, new_y);
        ENGINE_CORE_INFO("Window position callback occurred");
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        ENGINE_SEND_EVENT(WindowCloseEvent);
        ENGINE_INFO("Window close callback occurred");
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch (action)
        {
            case GLFW_PRESS:
            {
                ENGINE_SEND_EVENT(KeyPressedEvent, scancode, false);
                ENGINE_INFO("Window key press callback occurred");
                break;
            }
            case GLFW_RELEASE:
            {
                ENGINE_SEND_EVENT(KeyReleasedEvent, scancode);
                ENGINE_INFO("Window key released callback occurred");
                break;
            }
            case GLFW_REPEAT:
            {
                ENGINE_SEND_EVENT(KeyPressedEvent, scancode, true);
                ENGINE_INFO("Window key repeat callback occurred");
                break;
            }
        }
    });

    glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
    {
        ENGINE_SEND_EVENT(KeyTypedEvent, keycode);
        ENGINE_INFO("Window key typed callback occurred");
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
    {
        switch (action)
        {
            case GLFW_PRESS:
            {
                ENGINE_SEND_EVENT(MouseButtonPressedEvent, button);
                ENGINE_INFO("Window mouse button pressed callback occurred");
                break;
            }
            case GLFW_RELEASE:
            {
                ENGINE_SEND_EVENT(MouseButtonReleasedEvent, button);
                ENGINE_INFO("Window mouse button release callback occurred");
                break;
            }
        }
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
    {
        ENGINE_INFO("Window scroll callback occurred");
        ENGINE_SEND_EVENT(MouseScrolledEvent, xOffset, yOffset);
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
    {
        ENGINE_INFO("Window cursor pos callback occurred");
        ENGINE_SEND_EVENT(MouseMovedEvent, xPos, yPos);
    });
}

void Engine::LinuxWindow::Shutdown()
{
    glfwTerminate();
}






Engine::Window* Engine::CreateWindow()
{
    return new LinuxWindow(WindowProps());
}
