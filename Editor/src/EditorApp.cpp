#include <Bioba.h>


class LayerExample : public Bioba::Layer
{
public:
	LayerExample()
		: Layer(Bioba::LayerType::Layer,"Example")
	{
	}
	void OnUpdate() override {
		if (Bioba::Input::IsKeyPressed(BIO_KEY_F))
			BIO_EDITOR_TRACE("Key F was pressed");
	}
	void OnEvent(Bioba::Event& e) override
	{
		
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