#pragma once
#include "Core.h"
#include "Window.h"
#include "Application.h"
namespace Bioba {

	class BIO_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedPlatform(keycode); }
		static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedPlatform(button); }
		static std::pair<float,float> GetMousePosition() { return s_Instance->GetMousePositionPlatform(); }
		static float GetMouseX() { return s_Instance->GetMouseXPlatform(); }
		static float GetMouseY() { return s_Instance->GetMouseYPlatform(); }
		static void Init(Application* app);
		static void SetInputWindow(void* window) { m_Window = window; };
		static void* getInputWindow() { return m_Window; }
	protected:
		virtual bool IsKeyPressedPlatform(int keycode) = 0;
		virtual bool IsMouseButtonPressedPlatform(int button) = 0;
		virtual std::pair<float, float> GetMousePositionPlatform() = 0;
		virtual float GetMouseXPlatform() = 0;
		virtual float GetMouseYPlatform() = 0;

	private:
		static void* m_Window;
		static Input* s_Instance;
	};

}