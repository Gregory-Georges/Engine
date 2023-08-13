#include "../Engine/Engine.hpp"



class ExampleLayer : public Engine::Layer
{
public:

    ExampleLayer() :
        m_OrthographicCamera(-1.0, 1.0, -1.0, 1.0 ) //Init camera
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
            -0.5f, -0.5f,  0.0f,
             0.0f,  0.5f,  0.0f,
             0.5f, -0.5f,  0.0f
        };
        unsigned int indices[] =
        {
            0, 1, 2
        };

        VBO = Engine::VertexBuffer::Create(vertices, sizeof(vertices));
        IBO = Engine::IndexBuffer::Create(indices, sizeof(indices));

        Engine::BufferLayout buffer_layout(
        {
            Engine::Layout(Engine::Type::VEC3_FLOAT, "in_position")
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

            uniform mat4 u_viewprojmat;


            void main()
            {
                gl_Position = u_viewprojmat * vec4(in_position, 1.0);
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
        // Recalculate camera
        /////////////////////////////////////

        m_OrthographicCamera.SetRotation(glm::radians(90.0f));
        m_OrthographicCamera.SetPosition({0.5f, 0.5f, 0.0f});
        m_OrthographicCamera.RecalculateViewMatrix();



        /////////////////////////////////////
        //Draw test triangle
        /////////////////////////////////////

        Engine::RenderCommand::SetClearColor({0.0f, 0.0f, 0.8f, 1.0f});
        Engine::RenderCommand::Clear();

        Engine::Renderer::Begin(m_OrthographicCamera);
        Engine::Renderer::Submit(SHD, VAO);
        Engine::Renderer::End();
    }

    void OnEvent(Engine::Event* event) override
    {

    }



    void OnImGuiRender() override
    {

    }

private:

    Engine::OrthographicCamera m_OrthographicCamera;
    std::shared_ptr<Engine::VertexBuffer> VBO;
    std::shared_ptr<Engine::IndexBuffer> IBO;
    std::shared_ptr<Engine::VertexArray> VAO;
    std::shared_ptr<Engine::Shader> SHD;
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
