#pragma once

#ifdef BIO_WINDOWS_PLATFORM

	extern Bioba::Application* Bioba::CreateApplication();
	int main(int argc , char** argv)
	{
		Bioba::Log::InitLog();
		BIO_ENGINE_TRACE("TESTING TRACE MACRO WITH ENGINE");
		BIO_EDITOR_INFO("TESTING INFO MACRO WITH EDITOR");

		auto app = Bioba::CreateApplication();
		app->Start();
		delete app;
	}
#else
	#error Bioba Engine is supported only on windows
#endif