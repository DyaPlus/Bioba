#include <Bioba.h>

class Editor : public Bioba::Application
{
public:
	Editor() {

	}

	~Editor() {

	}
};

Bioba::Application* Bioba::CreateApplication() {
	return new Editor();
}