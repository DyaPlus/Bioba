#pragma once

#include "Bioba/Core.h"

namespace Bioba {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	#define EVENT_TYPE(type)	static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }
	class Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

	};


	// F will be deduced by the compiler
	template<typename T , typename F>
	bool DispatchEvent(Event& event ,const F& func) {
		if (event.GetEventType() == T::GetStaticType())
		{
			event.Handled = func(static_cast<T&>(event));
			return true;
		}
		return false;
	}

#define BIND_EVENT_FN(x) std::bind(&x , this , std::placeholders::_1)
#define DISPATCH_EVENT(req_event_type,in_event,f) DispatchEvent<req_event_type>(in_event,BIND_EVENT_FN(f))
}