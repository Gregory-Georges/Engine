#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED



//Graphical headers
//*********************************************************
#include "glad/glad.h"
#include "KHR/khrplatform.h"
#include <GLFW/glfw3.h>
//*********************************************************

//Layers
//*********************************************************
#include "Layer.hpp"
#include "LayerStack.hpp"
//*********************************************************

//Platform specific
//*********************************************************
#include "Platform/Platform.hpp"
//*********************************************************

//defines debug mode macros
//*********************************************************
#include "Debug.hpp"
#include "Core.hpp"
//*********************************************************

//Key codes
//*********************************************************
#include "KeyCodes.hpp"
//*********************************************************

//Engine interface
//*********************************************************
#include "Application.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "Input.hpp"
//*********************************************************

//Entry point
//*********************************************************
#include "EntryPoint.hpp"
//*********************************************************

//Events
//*********************************************************
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/Dispatcher.hpp"
#include "Events/EventManager.hpp"
#include "Events/Listener.hpp"
//*********************************************************



#endif // ENGINE_HPP_INCLUDED
