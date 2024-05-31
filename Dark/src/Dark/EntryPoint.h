#pragma once

#ifdef DK_PLATFORM_WINDOWS

extern Dark::Application* Dark::CreateApplication();

int main(int argc, char** agrv)
{
	auto app = Dark::CreateApplication();
	app->Run();
	delete app;
}

#endif // DK_PLATFORM_WINDOWS
