#pragma once

#include "Core.h"

#include "Events/Event.h"

namespace Dark {

	class DARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined in APP.
	Application* CreateApplication();

}