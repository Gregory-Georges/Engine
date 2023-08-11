#include "Engine/pch.hpp"
#include "RendererAPI.hpp"



namespace Engine
{
    RendererAPI::API RendererAPI::s_api = RendererAPI::API::OPEN_GL;

    RendererAPI::API RendererAPI::GetAPI()
    {
        return s_api;
    }
}
