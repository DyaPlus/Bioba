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
	Editor()
		:Bioba::Application()
	{
		
		PushLayer(new LayerExample());
		Bioba::ImGuiLayer* gui_layer = new Bioba::ImGuiLayer(GetWindowWidth(), GetWindowHeight());

		PushLayer(gui_layer);
	}

	~Editor() {

	}
};

Bioba::Application* Bioba::CreateApplication() {
	return new Editor();
}