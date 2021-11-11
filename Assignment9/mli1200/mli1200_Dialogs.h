#include <gtkmm.h>
#include <vector>
#include <iostream>

class Dialogs
{
public:
	static void message(std::string msg, std::string title);
	static std::string input(std::string msg, std::string title, std::string default_text = "", std::string cancel_text = "CANCLE");
	//static int input_i(std::string msg, std::string title, std::string default_text = "", std::string cancel_text = "CANCLE");
	static int question(std::string msg, std::string title, std::vector<std::string> buttons);
private:

};