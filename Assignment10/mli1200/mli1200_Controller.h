#pragma once

#include "mli1200_Zoo.h"
#include "mli1200_View.h"
#include <exception>

class Controller
{
public:
	class negative_id : public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "IDs cannot be negative.";
		}
	};
	class negative_age : public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "ages cannot be negative.";
		}
	};

	Controller();
	Controller(Zoo& z, View& v) : zoo(z), view(v){};
	void gui();
	void execute_gui_cmd(int cmd);
	std::vector<bool> get_multianimal_info(int);
	bool get_animal_info();
	std::vector<bool> load_from_file();
	void save_to_file();
private:
	Zoo& zoo;
	View& view;
};
