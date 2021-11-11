#include "dialog.h"
//#include <iostream>

int main (int argc, char* argv[])
{
    Gtk::Main kit(argc, argv);
    
    //Dialogs::message("test", "Title");
    
    //std::cout << Dialogs::input("What's your name?", "Question") << std::endl;
    
    std::vector<std::string> buttons = {"No", "Yes", "Maybe"};
    
    std::cout << Dialogs::question("does this work?", "Test", buttons) << std::endl;
    
    //Dialogs::image("moon.jpg", "Luna", "Or Selene if you're from ancient Greece"); 
    return 0;
}
