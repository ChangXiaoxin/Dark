#include "dkpch.h"
#include "Application.h"

#include "Dark/Events/ApplicationEvent.h"
#include "Dark/Log.h"

namespace Dark {
	
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);

		if (e.IsInCategory(EventCategoryApplication))
		{
		    DK_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			DK_TRACE(e);
		}

		while (true);
	}

}