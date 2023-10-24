#pragma once

#ifdef FL_PLATFORM_WINDOWS

extern Flare::Application* Flare::CreateApplication();

int main(int argc, char** argv)
{
	Flare::Log::Init();
	FL_CORE_WARN("Logger Initialized");

	FL_CLIENT_INFO("Flare Engine\n");
	auto Env = Flare::CreateApplication();
	Env->Run();
	delete Env;
}

#endif
