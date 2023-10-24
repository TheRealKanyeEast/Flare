#pragma once

#ifdef FL_PLATFORM_WINDOWS

extern Flare::Application* Flare::CreateApplication();

int main(int argc, char** argv)
{
	printf("Flare Engine\n");
	auto Env = Flare::CreateApplication();
	Env->Run();
	delete Env;
}

#endif
