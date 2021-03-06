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
		std::shared_ptr<Window> GetWindow();
		inline int GetWindowWidth();
		inline int GetWindowHeight();


	private:
		void OnEvent(Event& e);
		bool OnWindowClose(WindowCloseEvent& e);
		LayerStack m_LayerStack;
		std::shared_ptr<Window> m_Window;
		bool m_IsRunning;

	};

	Application* CreateApplication();
}

