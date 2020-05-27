#include "biopch.h"
#include "WinInput.h"

namespace Bioba {


	Input* Input::s_Instance = new WinInput();
	void* Input::m_Window = nullptr;

	void Input::Init(Application* app) {
		Input::SetInputWindow(app->GetWindow()->GetNativeWindow());
	}

	bool WinInput::IsKeyPressedPlatform(int keycode)
	{
		auto state = glfwGetKey(static_cast<GLFWwindow*>(Input::getInputWindow()), keycode);
		return state == GLFW_PRESS || state==GLFW_REPEAT;
	}

	bool WinInput::IsMouseButtonPressedPlatform(int button)
	{
		auto state = glfwGetMouseButton(static_cast<GLFWwindow*>(Input::getInputWindow()),button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WinInput::GetMousePositionPlatform()
	{
		double x;
		double y;
		glfwGetCursorPos(static_cast<GLFWwindow*>(Input::getInputWindow()), &x, &y);

		return { (float)x,(float)y };
	}

	float WinInput::GetMouseXPlatform()
	{
		double x;
		double y;
		glfwGetCursorPos(static_cast<GLFWwindow*>(Input::getInputWindow()), &x, &y);

		return x;
	}

	float WinInput::GetMouseYPlatform()
	{
		double x;
		double y;
		glfwGetCursorPos(static_cast<GLFWwindow*>(Input::getInputWindow()), &x, &y);

		return y;
	}
	

}