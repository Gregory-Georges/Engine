#include "Engine/pch.hpp"
#include "Engine/ImGuiFunctions.hpp"
#include "Engine/Application.hpp"

#include "Engine/Platform/OpenGL/GLHeaders.hpp"
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



    void ImGuiFunctions::ImGuiNewFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiFunctions::ImGuiDraw()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
