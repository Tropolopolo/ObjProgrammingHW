#include "mli1200_main_window.h"

Zoo z;
View v(z);
Controller c(z, v);
Main_window::Main_window()
{
	


	// /////////////////
   // G U I   S E T U P
   // /////////////////

	set_default_size(400, 200);

	// Put a vertical box container as the Window contents
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
	add(*vbox);

	// ///////
	// M E N U
	// Add a menu bar as the top item in the vertical box
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

	//     F I L E
	// Create a File menu and add to the menu bar
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_FILE", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	//         E D I T
 // Append New to the File menu
	Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_EDIT", true));
	menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_start_click));
	filemenu->append(*menuitem_new);

	//         S A V E F I L E
// Append New to the File menu
	Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_SAVEFILE", true));
	menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_save_click));
	filemenu->append(*menuitem_save);

	//         L O A D F I L E
// Append New to the File menu
	Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_LOADFILE", true));
	menuitem_load->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_load_click));
	filemenu->append(*menuitem_load);

	//         Q U I T
// Append Quit to the File menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	filemenu->append(*menuitem_quit);

	//     H E L P
		// Create a Help menu and add to the menu bar
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar->append(*menuitem_help);
	Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*helpmenu);

	//           A B O U T
	// Append About to the Help menu
	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
	menuitem_about->signal_activate().connect(sigc::mem_fun(*this,
		&Main_window::on_about_click));
	helpmenu->append(*menuitem_about);

	// /////////////
	// T O O L B A R
	// Add a toolbar to the vertical box, right below the menu
	Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
	vbox->add(*toolbar);

	//     Q U I T
	// Add a icon for quitting
	Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton{ Gtk::Stock::QUIT });
	quit_button->set_tooltip_markup("Exit game");
	quit_button->signal_clicked().connect(sigc::mem_fun(*this,
		&Main_window::on_quit_click));
	Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem{});
	sep->set_expand(true);  // The expanding sep forces the Quit button to the right
	toolbar->append(*sep);
	toolbar->append(*quit_button);


	
	
	// Make the box and everything in it visible
	vbox->show_all();
}

Main_window::~Main_window()
{
}

void Main_window::on_load_click()
{
	//std::vector<bool> truth = c.load_from_file();
	/*
	for (auto a : truth)
	{
		std::cout << a << std::endl;
	}
	*/
	Dialogs::message("This function does not work yet", "Error");
}

void Main_window::on_save_click()
{
	//c.save_to_file();
	Dialogs::message("This function does not work yet", "Error");
}

void Main_window::on_start_click()
{
	c.gui();
}

void Main_window::on_quit_click() {
	hide();
}

void Main_window::on_about_click() {
	Glib::ustring s = "<span size='24000' weight='bold'>Nim</span>\n<span size='large'>Copyright 2017 by George F. Rice</span>\n<span size='small'>Licensed under Creative Commons Attribution 4.0 International\nRobot icon created by Freepik, used under free attribution license</span>";
	Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
	dlg.run();
}