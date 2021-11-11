#ifndef _MLI1200_ANIMAL_H
#define	_MLI1200_ANIMAL_H


#include <iostream>
#include <sstream>

class Animal
{
	public:
		Animal();
		Animal(std::string n, int id, bool g, int a, std::string hs, std::string t);
		std::string get_name() const;
		int get_id_number() const;
		bool get_gender() const;
		int get_age() const;
		std::string get_health_status() const;
		std::string get_type() const;
		void set_name(std::string);
		void set_id_number(int);
		void set_gender(bool);
		void set_age(int);
		void set_health_status(std::string);
		void set_type(std::string);
		std::string to_string() const;
		friend std::ostream& operator<<(std::ostream&, const Animal&);
		bool operator==(Animal a) const;
	private:
		std::string name;
		int id_number;
		bool gender;
		int age;
		std::string health_status;
		std::string type;
};
#endif