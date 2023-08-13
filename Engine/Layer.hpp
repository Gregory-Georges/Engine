#ifndef LAYER_HPP
#define LAYER_HPP

#include "Engine/Events/Event.hpp"
#include "Engine/Core/Timestep.hpp"



namespace Engine
{
	class Layer
	{
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnRender() {}
		virtual void OnEvent(Event* event) {}

		virtual void OnImGuiRender() {}
	};
}



#endif // LAYER_HPP
