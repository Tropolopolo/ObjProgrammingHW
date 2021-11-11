#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H


#include "mli1200_Controller.h"

class Main_window : public Gtk::Window {
public: 
	Main_window();
	virtual ~Main_window();
protected:
	void on_save_click();
	void on_load_click();
	void on_start_click();
	void on_quit_click();
	void on_about_click();

private:
	
};
#endif