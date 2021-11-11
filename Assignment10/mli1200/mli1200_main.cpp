#include "mli1200_main_window.h"

int main(int argc, char* argv[])
{
	auto app = Gtk::Application::create(argc, argv, "Matthew Irvine cse1325");
	Main_window w;
	return app->run(w);
}
