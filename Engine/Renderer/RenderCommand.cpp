#include "Engine/pch.hpp"
#include "RenderCommand.hpp"
#include "Engine/Renderer/RendererAPI.hpp"
#include "Engine/Platform/OpenGL/OpenGLRendererAPI.hpp"



namespace Engine
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}
