#pragma once

#include "Layer.h"

namespace Calane
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer *layer);
		void popLayer(Layer *layer);

		void pushOverlay(Layer *overlay);
		void popOverlay(Layer *overlay);

		inline std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
		inline std::vector<Layer *>::iterator end() { return m_Layers.end(); }

		inline std::vector<Layer *>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		inline std::vector<Layer *>::reverse_iterator rend() { return m_Layers.rend(); }

	private:
		std::vector<Layer *> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}
