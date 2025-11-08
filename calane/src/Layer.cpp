#include "clpch.h"
#include "Layer.h"

namespace Calane
{
	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::onAttach()
	{
	}

	void Layer::onDetach()
	{
	}

	void Layer::onUpdate()
	{

	}

	void Layer::onEvent(Event &event)
	{
		CL_INFO(event);
	}
}
