#include "pch.hpp"
#include "ImGuiFunctions.hpp"
#include "Application.hpp"

#include "GL/GLHeaders.hpp"
#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"



namespace Engine
{
    //Singleton get
    ImGuiFunctions& ImGuiFunctions::Get()
    {
        static ImGuiFunctions imgui_f;
        return imgui_f;
    }



    void ImGuiFunctions::ImGuiInit()
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)(Application::GetInstance()->GetMainWindow().GetNativeWindow()), true);
        ImGui_ImplOpenGL3_Init("#version 410");
        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
    }

    void ImGuiFunctions::ImGuiTerminate()
    {

    }



    void ImGuiFunctions::ImGuiBegin(std::string window_name)
    {
        ImGui::Begin(window_name.c_str());
    }

    void ImGuiFunctions::ImGuiEnd()
    {
        ImGui::End();
    }
}
