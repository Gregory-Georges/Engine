#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED



//Layers
//*********************************************************
#include "Engine/Layer.hpp"
#include "Engine/LayerStack.hpp"
//*********************************************************



//Platform specific
//*********************************************************
#include "Engine/Platform/Platform.hpp"
//*********************************************************



//defines debug mode macros
//*********************************************************
#include "Engine/Debug.hpp"
#include "Engine/Core.hpp"
//*********************************************************



//Key codes
//*********************************************************
#include "Engine/KeyCodes.hpp"
//*********************************************************



//Engine interface
//*********************************************************
#include "Engine/Application.hpp"
#include "Engine/Log.hpp"
#include "Engine/Window.hpp"
#include "Engine/Input.hpp"
//*********************************************************



//Entry point
//*********************************************************
#include "Engine/EntryPoint.hpp"
//*********************************************************



//Events
//*********************************************************
#include "Engine/Events/Event.hpp"
#include "Engine/Events/ApplicationEvent.hpp"
#include "Engine/Events/KeyEvent.hpp"
#include "Engine/Events/MouseEvent.hpp"
//*********************************************************

//Graphics
//*********************************************************
#include "Engine/Renderer/OrthographicCamera.hpp"
#include "Engine/Renderer/RenderCommand.hpp"
#include "Engine/Renderer/Renderer.hpp"
//*********************************************************

//Components
//*********************************************************
#include "Engine/Transform.hpp"
//*********************************************************



#endif // ENGINE_HPP_INCLUDED
