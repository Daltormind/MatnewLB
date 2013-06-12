//Destruct Deallocates memory space

#include "wet.h"


wet::~wet(void) 
	
{
	
	
	delete []p;
	delete []mu;
	delete []C;
	delete []rho;
	
	
	delete []u;
	//delete []dC;
	//delete []dmu;
	//delete []drho;
	//delete []dp;
	
	delete []g;
	delete []h;
	//delete []geq;
	//delete []heq;
	//delete []dgamma;
	//delete []gamhold;
	//delete []gamma;
	//delete []Ct;
	//delete []ht;
	delete []muh;
	delete []f;

}