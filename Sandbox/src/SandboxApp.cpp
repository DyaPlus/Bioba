#include <Bioba.h>

class Sandbox : public Bioba::Application
{
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Bioba::Application* Bioba::CreateApplication() {
	return new Sandbox();
}