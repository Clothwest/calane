#pragma once

#include "Event/Event.h"

namespace Calane
{
	class Layer
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void onAttach();
		virtual void onDetach();
		virtual void onUpdate();
		virtual void onEvent(Event &event);
	};
}

