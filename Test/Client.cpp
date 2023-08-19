#include "../Engine/Engine.hpp"

#include "Dependencies/imgui/imgui.h"
#include "Engine/ImGuiFunctions.hpp"
#include "glm/gtc/type_ptr.hpp"



class ExampleLayer : public Engine::Layer
{
public:

    ExampleLayer() :
        m_OrthographicCamera(4, 2), m_color(1.0f)
    {

    }

    void OnAttach() override
    {
        /////////////////////////////////////
        // Setup VAO
        /////////////////////////////////////

        VAO = Engine::VertexArray::Create();

        //Fill buffers with data
        float vertices[] =
        {   //Positions           //Texture coordinates
            -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
             0.5f,  0.5f,  0.0f,  1.0f,  1.0f,
             0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f,  0.5f,  0.0f,  0.0f,  1.0f
        };
        unsigned int indices[] =
        {
            0, 2, 1,
            0, 3, 1
        };

        VBO = Engine::VertexBuffer::Create(vertices, sizeof(vertices));
        IBO = Engine::IndexBuffer::Create(indices, sizeof(indices));

        Engine::BufferLayout buffer_layout(
        {
            Engine::Layout(Engine::Type::VEC3_FLOAT, "in_position"),
            Engine::Layout(Engine::Type::VEC2_FLOAT, "in_TexCoords")
        });
        VBO->SetLayout(buffer_layout);

        VAO->AddVertexBuffer(VBO);
        VAO->SetIndexBuffer(IBO);
        VAO->Unbind();



        /////////////////////////////////////
        // Load assets
        /////////////////////////////////////

        TXT = Engine::Texture2D::Create("assets/textures/chess.png");
        SHD = Engine::Shader::Create("assets/shaders/default.glsl");
    }

    void OnDetach() override
    {

    }

    void OnUpdate(Engine::Timestep ts) override
    {

    }

    void OnRender() override
    {
        /////////////////////////////////////
        //Draw test triangle
        /////////////////////////////////////

        Engine::RenderCommand::SetClearColor({0.5f, 0.5f, 0.8f, 1.0f});
        Engine::RenderCommand::Clear();

        TXT->Bind();

        Engine::Renderer::Begin(m_OrthographicCamera);
        Engine::Renderer::Submit(SHD, VAO, TSF.GetModelMatrix());
        Engine::Renderer::End();
    }

    void OnEvent(Engine::Event* event) override
    {
        Engine::EventDispatcher event_dispatcher(*event);
        event_dispatcher.Dispatch<Engine::WindowResizeEvent>([this](Engine::WindowResizeEvent f_ev)
        {
            this->m_OrthographicCamera.RecalculateProjMatrix(f_ev.GetNewX(), f_ev.GetNewY());
            this->m_OrthographicCamera.RecalculateViewProjMatrix();
            return false;
        });
    }



    void OnImGuiRender() override
    {
        ImGui::Begin("Test");
        ImGui::ColorEdit3("Color", glm::value_ptr(m_color));
        ImGui::End();
    }

private:

    glm::vec3 m_color;
    Engine::Transform TSF;
    Engine::OrthographicCamera m_OrthographicCamera;
    Engine::Ref<Engine::VertexBuffer> VBO;
    Engine::Ref<Engine::IndexBuffer> IBO;
    Engine::Ref<Engine::VertexArray> VAO;
    Engine::Ref<Engine::Shader> SHD;
    Engine::Ref<Engine::Texture2D> TXT;
};



class Sandbox : public Engine::Application
{
public:

    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};

Engine::Application* Engine::CreateApplication()
{
    return new Sandbox();
}
