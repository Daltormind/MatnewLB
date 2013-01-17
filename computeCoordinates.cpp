//Computecoordinate

#include "wet.h"

void wet::computecoordinates(int k)
	{
		xk=int (k/float(Lz*Ly));
		yk=int((k-xk*Lz*Ly)/float(Lz));
		zk=k-xk*Ly*Lz-yk*Lz;
	
	
	
	}