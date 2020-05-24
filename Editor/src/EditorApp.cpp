#include <Bioba.h>


class LayerExample : public Bioba::Layer
{
public:
	LayerExample()
		: Layer(Bioba::LayerType::Layer,"Example")
	{
	}
	void OnEvent(Bioba::Event& e) override
	{
		BIO_EDITOR_TRACE(e.ToString());
	}
};


class Editor : public Bioba::Application
{
public:
	Editor() {
		PushLayer(new LayerExample());

	}

	~Editor() {

	}
};

Bioba::Application* Bioba::CreateApplication() {
	return new Editor();
}