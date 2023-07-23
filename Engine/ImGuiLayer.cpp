#include "pch.hpp"
#include "ImGuiLayer.hpp"

#include <iostream>

#include "Application.hpp"

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"



namespace Engine
{
    void ImGuiLayer::OnAttach()
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

    void ImGuiLayer::OnImGuiRender()
    {
        // feed inputs to dear imgui, start new frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //Tell what to render
        ImGui::Begin("Demo window");
        ImGui::Button("Hello!");
        ImGui::End();

        //Render ImGui
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiLayer::OnEvent(Event* event)
    {

    }
}
