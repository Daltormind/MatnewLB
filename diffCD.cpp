//Computes differentials using second order central difference scheme

#include "wet.h"

void wet::diffCD(double& x[const_cast<int>(ProcessN)] , double& dx[const_cast<int>(ProcessN)][3])
{
	for(k=k1;k<k2;k++)
		{
		
			dx[k][0]=/*(*/x[d[k][0]];//-x[d[k][1]])/t1/2+(x[d[k][6]]+x[d[k][8]]+x[d[k][14]]+x[d[k][16]]-x[d[k][7]]-x[d[k][9]]-x[d[k][15]]-x[d[k][17]])/t2/2;

			//dx[k][1]=(x[d[k][2]]-x[d[k][3]])/t1/2+(x[d[k][6]]+x[d[k][7]]+x[d[k][10]]+x[d[k][12]]-x[d[k][8]]-x[d[k][9]]-x[d[k][11]]-x[d[k][13]])/t2/2;

			//dx[k][2]=(x[d[k][4]]-x[d[k][5]])/t1/2+(x[d[k][10]]+x[d[k][11]]+x[d[k][14]]+x[d[k][15]]-x[d[k][12]]-x[d[k][13]]-x[d[k][16]]-x[d[k][17]])/t2/2;
		
		
		
		}


}