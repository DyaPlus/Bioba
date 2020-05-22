#pragma once
#include "Core.h"

namespace Bioba
{
	class BIO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Start();


	};

	Application* CreateApplication();
}

