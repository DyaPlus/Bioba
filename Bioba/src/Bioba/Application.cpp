#include "biopch.h"
#include "Application.h"

Bioba::Application::Application()
	:m_Window(std::unique_ptr<Window>(Window::Create())) , m_IsRunning(true)
{
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
