#include "Sales_Manager.h"

double Sales_Manager::pay()
{
	double amount_paid = total_sales*comission_rate + yearly_salary/12;
	total_sales = 0;
	return amount_paid;
}
