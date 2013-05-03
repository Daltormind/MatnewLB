//Compute free energy to check what is going on

#include"wet.h"

void wet::computefreeenergy()

{
	El=0.0;
	Eg=0.0;
	Ei=0.0;
	
	for(k=k1;k<k2;k++)
	{
	
	if(C[k]>=0.9)
	{
		El+=mu[k];
	}
	
	if(C[k]<=0.1)
	{
		Eg+=mu[k];
	}
	
	if(C[k]>0.1 and C[k]<0.9)
	{
		Ei+=mu[k];
	}

	}

	Et=Eg+Ei+El;
}