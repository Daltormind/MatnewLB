//Initialise surface

#include "wet.h"

void wet::initialisesurface()
{
	
	for(k=k1;k<k2;k++)
	{
	
	computecoordinates(k);
	
	mask[k]=0.0;
	
	
	if(xk>xs )
	{
		mask[k]=28;
		
	}
	}
	
	for(k=k1;k<k2;k++)
	{
		if(mask[d[k][0]]==28 and mask[k]!=28){mask[k]=1;}
		if(mask[d[k][1]]==28 and mask[k]!=28){mask[k]=2;}
		
		
	
	}
	
	for(k=k1;k<k2;k++)
	{
		if(mask[d[k][1]]==2){mask[k]=-2;}
		if(mask[d[k][0]]==1){mask[k]=-1;}
	}
}