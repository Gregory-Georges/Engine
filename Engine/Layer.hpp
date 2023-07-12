#ifndef LAYER_HPP
#define LAYER_HPP

#include "Events/Event.hpp"



namespace Engine
{
	class Layer
	{
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnRender() {}
		virtual void OnEvent(Event& event) {}
	};
}



#endif // LAYER_HPP
