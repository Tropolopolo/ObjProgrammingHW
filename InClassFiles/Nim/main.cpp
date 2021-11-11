#include "main_window.h"
//#include <gtkmm.h>
//#include <iostream>

int main (int argc, char *argv[])
{
  auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.nim");
  // Instance a Window
  Main_window win;

  // Set the window title
  win.set_title("Nim");

  //Show the window and returns when it is closed or hidden
  return app->run(win);
}
