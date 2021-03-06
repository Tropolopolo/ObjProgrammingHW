#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "nim.h"

class Main_window : public Gtk::Window {
    public:
        Main_window();
        virtual ~Main_window();
    protected: //callbacks
        void on_new_game_click();        // Create a new game
        void on_button1_click();         // Select one stick from pile
        void on_button2_click();         // Select two sticks from pile
        void on_button3_click();         // Select three sticks from pile
        void on_computer_player_click(); // Enable / disable computer player
        void on_about_click();           // Display About dialog
        void on_quit_click();            // Exit the game

    private:
        void set_sticks();               // Update display, robot move
        Nim *nim;
        //GUI widgets
        Gtk::Label *sticks;              // Display of sticks on game board
        Gtk::Label *msg;                      // Status message display
        Gtk::ToolButton *button1;             // Button to select 1 stick
        Gtk::Image *button1_on_image;         //   Image when active
        Gtk::Image *button1_off_image;        //   Image when inactive
        Gtk::ToolButton *button2;             // Button to select 2 sticks
        Gtk::Image *button2_on_image;
        Gtk::Image *button2_off_image;
        Gtk::ToolButton *button3;             // Button to select 3 sticks
        Gtk::Image *button3_on_image;
        Gtk::Image *button3_off_image;
        Gtk::ToggleToolButton *computer_player;  // Button to enable robot
};
#endif
