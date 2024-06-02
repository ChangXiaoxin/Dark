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
		DK_INFO("Demo Layer: Update");
	}

	void OnEvent(Dark::Event& event) override
	{
		DK_TRACE("{0}", event);
	}
};


class Sandbox : public Dark::Application
{
public:

	Sandbox()
	{
		PushLayer(new DemoLayer());
	}

	~Sandbox()
	{

	}

};

Dark::Application* Dark::CreateApplication()
{
	return new Sandbox();
}