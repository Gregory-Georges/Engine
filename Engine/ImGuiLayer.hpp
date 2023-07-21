#ifndef IMGUILAYER_H_INCLUDED
#define IMGUILAYER_H_INCLUDED

#include "Layer.hpp"




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
    };
}



#endif // IMGUILAYER_H_INCLUDED
