#include "wet.h"

void wet::diffMDt(double B[],double dBt[])
{
	if(dimensions==1)
	{
		if(a==1)
		{
			dBt[0]=1/4*(5*B[d[k][0]]-B[d[k][1]]-3*B[k]-B[d[d[k][0]][0]]);
			dBt[1]=0.0;
			dBt[2]=0.0;
		}
		
		if(a==2)
		{
			dBt[0]=1/4*(B[d[k][0]]+3*B[d[k][1]]-3*B[k]-B[d[d[k][1]][1]]);
			dBt[1];
			dBt[2];
		}
	}
	
	if(dimensions==2)
	{
		if(a==1)
		{
		
		}
	}
}