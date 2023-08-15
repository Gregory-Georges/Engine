#include "../Engine/Engine.hpp"

#include "Dependencies/imgui/imgui.h"
#include "Engine/ImGuiFunctions.hpp"
#include "glm/gtc/type_ptr.hpp"



class ExampleLayer : public Engine::Layer
{
public:

    ExampleLayer() :
        m_OrthographicCamera(-1.0, 1.0, -1.0, 1.0 ), m_color(1.0f)
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
        {
            -0.5f, -0.5f,  0.0f,  0.0f,  0.0f,
             0.0f,  0.5f,  0.0f,  0.5f,  1.0f,
             0.5f, -0.5f,  0.0f,  1.0f,  0.0f
        };
        unsigned int indices[] =
        {
            0, 1, 2
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
        // Setup shader
        /////////////////////////////////////

        std::string vertex_shd = R"(
            #version 410


            layout (location = 0) in vec3 in_position;

            uniform mat4 u_modelmat;
            uniform mat4 u_viewprojmat;


            void main()
            {
                gl_Position = u_viewprojmat * u_modelmat * vec4(in_position, 1.0);
            }
        )";

        std::string fragment_shd = R"(
            #version 410


            out vec4 out_color;


            void main()
            {
                out_color = vec4(1.0, 0.0, 0.0, 1.0);
            }
        )";

        SHD = Engine::Shader::CreateShader(vertex_shd, fragment_shd);
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

        TSF.SetPosition(glm::vec3(0.5f, 0.5f, 0.0f));
        TSF.SetRotation(glm::vec3(0.0f, 0.0f, 90.0f));
        TSF.SetScale(glm::vec3(1.0f, 0.5f, 1.0f));
        TSF.RecalculateModelMatrix();

        Engine::Renderer::Begin(m_OrthographicCamera);
        Engine::Renderer::Submit(SHD, VAO, TSF.GetModelMatrix());
        Engine::Renderer::End();
    }

    void OnEvent(Engine::Event* event) override
    {

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
