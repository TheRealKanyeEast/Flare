#include <Flare.h>

class Sandbox : public Flare::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Flare::Application* Flare::CreateApplication()
{
	return new Sandbox();
}