#pragma once

#include "Application.h"

#ifdef BIO_WINDOWS_PLATFORM
	extern Bioba::Application* Bioba::CreateApplication();
	int main(int argc , char** argv)
	{
		auto app = Bioba::CreateApplication();
		app->Start();
		delete app;
	}
#else
	#error Bioba Engine is supported only on windows
#endif