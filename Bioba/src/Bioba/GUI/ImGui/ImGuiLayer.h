#pragma once
#include "Bioba/Core.h"
#include "Bioba/Layer.h"

namespace Bioba {

	class BIO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(int width, int height);
		virtual ~ImGuiLayer();
		virtual void OnEvent(Event& e) override {}
		virtual void OnUpdate() override;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
	private:
		double m_Time;
		int m_Width;
		int m_Height;
	};

}