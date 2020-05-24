#pragma once

#ifdef BIO_WINDOWS_PLATFORM

	extern Bioba::Application* Bioba::CreateApplication();

	int main(int argc , char** argv)
	{
		Bioba::Log::InitLog();

		auto app = Bioba::CreateApplication();
		app->Start();
		delete app;
	}
#else
	#error Bioba Engine is supported only on windows
#endif