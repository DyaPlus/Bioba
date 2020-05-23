#pragma once

#ifdef BIO_WINDOWS_PLATFORM

	extern Bioba::Application* Bioba::CreateApplication();

	int main(int argc , char** argv)
	{
		Bioba::Log::InitLog();
		Bioba::KeyPressedEvent key_event(1,0);
		BIO_ENGINE_TRACE(key_event.ToString());

		auto app = Bioba::CreateApplication();
		app->Start();
		delete app;
	}
#else
	#error Bioba Engine is supported only on windows
#endif