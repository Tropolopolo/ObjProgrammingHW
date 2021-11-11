#include "mli1200_Controller.h"

int main()
{
	Zoo z;
	View v(z);
	Controller c(z, v);
	c.cli();
	return 0;
}

