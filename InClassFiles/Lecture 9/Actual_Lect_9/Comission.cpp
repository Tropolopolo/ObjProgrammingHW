#include "Comission.h"

void Comission::add_sales(double sales)
{
	total_sales += sales;
}

double Comission::pay()
{
	double amount_paid = total_sales * comission_rate;
	total_sales = 0;
	return amount_paid;
}
