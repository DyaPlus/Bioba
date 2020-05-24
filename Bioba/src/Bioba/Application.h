#pragma once
#include "Core.h"
#include "Bioba/Log.h"
#include "Window.h"
#include "biopch.h"
#include "LayerStack.h"

namespace Bioba
{
	class BIO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Start();
		void PushLayer(Layer* layer);
		
	private:
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning;

	};

	Application* CreateApplication();
}

