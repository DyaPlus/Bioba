#pragma once
#include "Bioba/Input.h"
#include "GLFW/glfw3.h"

namespace Bioba {

	class WinInput : public Input
	{
	protected:
		virtual bool IsKeyPressedPlatform(int keycode) override;
		virtual bool IsMouseButtonPressedPlatform(int button) override;
		virtual std::pair<float, float> GetMousePositionPlatform() override;
		virtual float GetMouseXPlatform() override;
		virtual float GetMouseYPlatform() override;
	};

}
