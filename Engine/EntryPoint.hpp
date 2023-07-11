#ifndef ENTRYPOINT_HPP_INCLUDED
#define ENTRYPOINT_HPP_INCLUDED

#include "Application.hpp"



//Defined in client
extern Engine::Application* Engine::CreateApplication();



//
// Main
//
int main()
{
    //Create application
    auto* app = Engine::CreateApplication();

    //Push ImGui overlay
    Engine::ImGuiLayer* igl = new Engine::ImGuiLayer();
    app->PushOverlay(igl);

    //Program loop
    while(app->m_isRunning)
        app->Run();

    //Cleanup
    delete app;
}



#endif // ENTRYPOINT_HPP_INCLUDED
