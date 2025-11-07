#include "clpch.h"
#include "Calane.h"


#if defined CL_RELEASE
int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd
)
#elif defined CL_DEBUG
int main()
#endif
{
#ifdef CL_DEBUG
	Calane::Log::init();
#endif
	CL_INFO("Log initialized");

	Calane::Application *app = new Calane::Application();
	app->run();
	delete app;
}
