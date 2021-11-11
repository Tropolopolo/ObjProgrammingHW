#include "Comission.h"
#include "Salaried.h"

class Sales_Manager : public Comission, public Salaried
{
	public:
		Sales_Manager(std::string n = "John Doe", int id = 123, double cr = 0.05, double ts = 0, double ys = 50000) : Comission(n, id, cr, ts), Salaried(n, id, ys) {};
		double pay();
	private:
};
