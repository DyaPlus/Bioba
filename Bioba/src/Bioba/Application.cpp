#include "biopch.h"
#include "Application.h"
#include "glad/glad.h"
#include "Input.h"

#define BIND_EVENT_FN(x) std::bind(&Bioba::Application::x,this,std::placeholders::_1)

Bioba::Application::Application()
	:m_Window(std::unique_ptr<Window>(Window::Create())) , m_IsRunning(true)
{
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	Input::Init(this);
}

Bioba::Application::~Application()
{
}

void Bioba::Application::Start()
{
	while (m_IsRunning)
	{
		//TODO Remove 
		glClearColor(0.2, 0.4, 0.2, 0.1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (auto& layer : m_LayerStack)
		{
			layer->OnUpdate();
		}
		m_Window->OnUpdate();

		bool presses = Input::IsMouseButtonPressed(1);
		if (presses)
			BIO_ENGINE_INFO("Mouse Button 1 is presses");
		
	}
}

void Bioba::Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

std::shared_ptr<Bioba::Window> Bioba::Application::GetWindow()
{
	return m_Window;
}

inline int Bioba::Application::GetWindowWidth()
{
	if (m_Window)
	{
		return m_Window->GetWidth();
	}
}

inline int Bioba::Application::GetWindowHeight()
{
	if (m_Window)
	{
		return m_Window->GetHeight();
	}
}

void Bioba::Application::OnEvent(Event& e)
{

	DispatchEvent<WindowCloseEvent>(e, BIND_EVENT_FN(OnWindowClose));


	for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); it++)
	{
		(*it)->OnEvent(e);
		if (e.Handled)
		{
			break; //A Layer found its event so don't continue
		}
	}

}

bool Bioba::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_IsRunning = false;
	return true;
}
