#pragma once

#ifdef DK_PLATFORM_WINDOWS

extern Dark::Application* Dark::CreateApplication();

int main(int argc, char** agrv)
{
	Dark::Log::Init();
	DK_CORE_WARN("Initialized log!");
	int a = 6;
	DK_INFO("Hello! Var = {0}", a);

	auto app = Dark::CreateApplication();
	app->Run();
	delete app;
}

#endif // DK_PLATFORM_WINDOWS
