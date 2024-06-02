#pragma once

#include "Core.h"
#include "Dark/LayerStack.h"
#include "Dark/Events/Event.h"
#include "Dark/Events/ApplicationEvent.h"

#include "Window.h"

namespace Dark {

	class DARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in APP.
	Application* CreateApplication();

}