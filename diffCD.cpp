//Computes differentials using second order central difference scheme

#include "wet.h"

void wet::diffCD(double B[], double dB[])
{
	
		if (dimensions==3)
		{
			dB[0]=/*(*/B[0];//-B[d[k][1]])/t1/2+(B[d[k][6]]+B[d[k][8]]+B[d[k][14]]+B[d[k][16]]-B[d[k][7]]-B[d[k][9]]-B[d[k][15]]-B[d[k][17]])/t2/2;

			//dB[k][1]=(B[d[k][2]]-B[d[k][3]])/t1/2+(B[d[k][6]]+B[d[k][7]]+B[d[k][10]]+B[d[k][12]]-B[d[k][8]]-B[d[k][9]]-B[d[k][11]]-B[d[k][13]])/t2/2;

			//dB[k][2]=(B[d[k][4]]-B[d[k][5]])/t1/2+(B[d[k][10]]+B[d[k][11]]+B[d[k][14]]+B[d[k][15]]-B[d[k][12]]-B[d[k][13]]-B[d[k][16]]-B[d[k][17]])/t2/2;
		}
		
		
		if (dimensions==1)
		{
			dB[0]=0.25*(B[d[k][0]]-B[d[k][1]]);
			dB[1]=0.0;
			dB[2]=0.0;
		
		}
		
		


}