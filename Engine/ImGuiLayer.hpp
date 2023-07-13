#ifndef IMGUILAYER_H_INCLUDED
#define IMGUILAYER_H_INCLUDED

#include "Layer.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_opengl3_loader.h"
#include "backends/imgui_impl_glfw.h"




namespace Engine
{
    class ImGuiLayer : public Layer
    {
    public:

        ImGuiLayer() = default;
        ~ImGuiLayer() = default;

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnRender() override;
        void OnEvent(Event& event) override;
    };
}



#endif // IMGUILAYER_H_INCLUDED
