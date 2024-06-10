#pragma once

#include "dkpch.h"

#include "Dark/Core.h"
#include "Dark/Events/GamepadEvent.h"

namespace Dark {

	struct GamepadProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		GamepadProps(const std::string& title = "Dark Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{

		}
	};

	// Interface representing a desktop system based Gamepad.
	class DARK_API Gamepad
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Gamepad() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		static Gamepad* Create(const GamepadProps& props =GamepadProps ());
	};

}
