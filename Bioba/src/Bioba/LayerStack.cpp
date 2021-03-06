#include "biopch.h"
#include "LayerStack.h"
#include "Log.h" 

namespace Bioba {

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		if (layer->GetType() == LayerType::Layer) 
		{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
		}
		else if (layer->GetType() == LayerType::Overlay)
		{
			m_Layers.emplace_back(layer);
		}
		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		if (layer->GetType() == LayerType::Layer)
		{
			auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
			if (it != m_Layers.begin() + m_LayerInsertIndex)
			{
				layer->OnDetach();
				m_Layers.erase(it);
				m_LayerInsertIndex--;
			}
		}
		else if (layer->GetType() == LayerType::Overlay)
		{
			auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), layer);
			if (it != m_Layers.end())
			{
				layer->OnDetach();
				m_Layers.erase(it);
			}
		} 
		else
		{
			BIO_ENGINE_WARN("Couldn't find the layer : {0}", layer->GetName());
		}
		
	}

}