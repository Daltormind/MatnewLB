//Computecoordinate

#include "wet.h"

void wet::computecoordinates(int k)
	{
		
		/*
		xk=int (k/float(Lz*Ly));
		yk=int((k-xk*Lz*Ly)/float(Lz));
		zk=k-xk*Ly*Lz-yk*Lz;
		*/
	
		int kTot;

	if(rank<ROOT)
	{
		kTot=k+rank*(k2-k1)-k1;
		xk=int(kTot/(float) (LZ*LY));		//Index node of x coordinate 
		yk=int((kTot-xk*LZ*LY)/(float) LZ);	//Index node of y coordinate
		zk=kTot-xk*LZ*LY-yk*LZ;			//Index node of z coordinate
	}
	if(rank==ROOT)
	{
		kTot=k+rank*(k2-(LX%size+1)*k1)-k1;
		xk=int(kTot/(float) (LZ*LY));		//Index node of x coordinate 
		yk=int((kTot-xk*LZ*LY)/(float) LZ);	//Index node of y coordinate
		zk=kTot-xk*LZ*LY-yk*LZ;			//Index node of z coordinate
	}
	if(rank>ROOT)
	{
		kTot=k+rank*(k2-k1)+(LX%size-1)*k1;
		xk=int(kTot/(float) (LZ*LY));		//Index node of x coordinate 
		yk=int((kTot-xk*LZ*LY)/(float) LZ);	//Index node of y coordinate
		zk=kTot-xk*LZ*LY-yk*LZ;			//Index node of z coordinate
	}
	
	
	}