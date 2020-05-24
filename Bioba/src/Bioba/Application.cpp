#include "biopch.h"
#include "Application.h"

#define BIND_EVENT_FN(x) std::bind(&Bioba::Application::x,this,std::placeholders::_1)

Bioba::Application::Application()
	:m_Window(std::unique_ptr<Window>(Window::Create())) , m_IsRunning(true)
{
	m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Bioba::Application::~Application()
{
}

void Bioba::Application::Start()
{
	while (m_IsRunning)
	{
		m_Window->OnUpdate();
	}
}

void Bioba::Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void Bioba::Application::OnEvent(Event& e)
{
	DispatchEvent<WindowCloseEvent>(e, BIND_EVENT_FN(OnWindowClose));
	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
	{
		(*--it)->OnEvent(e);
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
