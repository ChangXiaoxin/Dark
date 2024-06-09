#include "Dark.h"

class DemoLayer : public Dark::Layer
{
public:
	DemoLayer()
		: Layer("Demo Layer")
	{
	}

	void OnUpdate() override
	{
		//DK_INFO("Demo Layer: Update");

		if (Dark::Input::IsKeyPressed(DK_KEY_TAB))
		{
			DK_TRACE("Tab key is pressed!");
		}
	}

	void OnEvent(Dark::Event& event) override
	{
		//DK_TRACE("{0}", event);
		if (event.GetEventType() == Dark::EventType::KeyPressed)
		{
			Dark::KeyPressedEvent& e = (Dark::KeyPressedEvent&)event;
			DK_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Dark::Application
{
public:

	Sandbox()
	{
		PushLayer(new DemoLayer());
		PushOverlay(new Dark::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Dark::Application* Dark::CreateApplication()
{
	return new Sandbox();
}