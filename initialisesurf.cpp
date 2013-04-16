//Initialise surface

#include "wet.h"

void wet::initialisesurface()
{
	
	for(k=k1;k<k2;k++)
	{
	
	computecoordinates(k);
	
	if(abs(xs-xk)<wx and abs(ys-yk)<wy)
	{
		mask[k]=28;
	}
	}
}