#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED



//Platform specific
//************************************
#include "Platform/Platform.hpp"
#include "Platform/LinuxWindow.hpp"
//************************************

//defines debug mode macros
//************************************
#include "Debug.hpp"
#include "Core.hpp"
//************************************

//Key codes
//************************************
#include "KeyCodes.hpp"
//************************************

//Engine
//************************************
#include "Application.hpp"
#include "Log.hpp"
#include "Window.hpp"
//************************************

//Entry point
//************************************
#include "EntryPoint.hpp"
//************************************

//Events
//************************************
#include "Events/Event.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Events/KeyEvent.hpp"
#include "Events/MouseEvent.hpp"
#include "Events/EventManager.hpp"
//************************************



#endif // ENGINE_HPP_INCLUDED
