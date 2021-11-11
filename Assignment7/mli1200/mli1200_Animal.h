#ifndef _MLI1200_ANIMAL_H
#define	_MLI1200_ANIMAL_H


#include <iostream>
#include <sstream>

class Animal
{
	public:
		Animal(std::string n = "matt", int id = 1, bool g = 0, int a = 20, std::string hs = "Good", std::string t = "Animal", std::string s = "Dog") : name(n), id_number(id), gender(g), age(a), health_status(hs), type(t), species(s) {};
		std::string get_name() const;
		int get_id_number() const;
		bool get_gender() const;
		int get_age() const;
		std::string get_health_status() const;
		std::string get_type() const;
		std::string get_species() const;
		void set_name(std::string);
		void set_id_number(int);
		void set_gender(bool);
		void set_age(int);
		void set_health_status(std::string);
		void set_type(std::string);
		void set_species(std::string);
		virtual std::string to_string() const;
		virtual std::string act();
		//friend std::ostream& operator<<(std::ostream&, const Animal&);
		bool operator==(Animal a) const;
	protected:
		std::string name;
		int id_number;
		bool gender;
		int age;
		std::string health_status;
		std::string type;
		std::string species;
};
#endif