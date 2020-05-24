#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Bioba/Events/KeyEvent.h"
#include "Bioba/Events/MouseEvent.h"
#include "Bioba/Events/ApplicationEvent.h"

namespace Bioba {
	enum class LayerType {
		Layer , Overlay
	};
	class BIO_API Layer
	{
	public:
		Layer(const LayerType& type, const std::string& name = "Layer");
		virtual ~Layer() {}
		virtual void OnEvent(Event& e) {}
		virtual void OnUpdate() {}
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		const std::string& GetName() const { return m_DebugName; }
		inline const LayerType GetType() const { return m_Type; }
	protected:
		std::string m_DebugName;
		LayerType m_Type;
	};
}