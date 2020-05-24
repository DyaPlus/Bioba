#pragma once
#include "Core.h"
#include "Window.h"
#include "biopch.h"

namespace Bioba
{
	class BIO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Start();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning;

	};

	Application* CreateApplication();
}

