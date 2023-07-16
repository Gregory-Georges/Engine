#include "../pch.hpp"
#include "../Input.hpp"
#include "../Application.hpp"



namespace Engine
{
    std::pair<float, float> Input::GetMousePos()
    {
        double x, y;
        glfwGetCursorPos((GLFWwindow*)(Application::GetInstance()->GetMainWindow().GetNativeWindow()), &x, &y);
        return {float(x), float(y)};
    }



    bool Input::GetKey(int keycode)
    {
        int state;
        state = glfwGetKey((GLFWwindow*)(Application::GetInstance()->GetMainWindow().GetNativeWindow()), keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }



    bool Input::GetMouseButton(int mousecode)
    {
        int state;
        state = glfwGetMouseButton((GLFWwindow*)(Application::GetInstance()->GetMainWindow().GetNativeWindow()), mousecode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
}
