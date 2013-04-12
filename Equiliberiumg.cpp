//Equilibrium computes the equilibrium values of the pressure and momentum equations 

#include "wet.h"

void wet ::equiliberiumg()

{
	if(mask[k]!=28)
	{
	for(k=k1;k<k2;k++)
	{

		for(a=0;a<Q;a++)
		{	
			if(mask[k]==0)
			{
			if(dimensions==3)
			{
			dgamma[k][a]=((gamma[d[k][0]][a]-gamma[d[k][1]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][8]][a]+gamma[d[k][14]][a]+gamma[d[k][16]][a]-gamma[d[k][7]][a]-gamma[d[k][9]][a]-gamma[d[k][15]][a]-gamma[d[k][17]][a])*t2/2)*(e[a][0]-u[k][0]);
	
			dgamma[k][a]+=((gamma[d[k][2]][a]-gamma[d[k][3]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][7]][a]+gamma[d[k][10]][a]+gamma[d[k][12]][a]-gamma[d[k][8]][a]-gamma[d[k][9]][a]-gamma[d[k][11]][a]-gamma[d[k][13]][a])*t2/2)*(e[a][1]-u[k][1]);
	
			dgamma[k][a]+=((gamma[d[k][4]][a]-gamma[d[k][5]][a])*t1/2+(gamma[d[k][10]][a]+gamma[d[k][11]][a]+gamma[d[k][14]][a]+gamma[d[k][15]][a]-gamma[d[k][12]][a]-gamma[d[k][13]][a]-gamma[d[k][16]][a]-gamma[d[k][17]][a])*t2/2)*(e[a][2]-u[k][2]);
			}
			
			if(dimensions==2)
			{
			dgamma[k][a]=((gamma[d[k][0]][a]-gamma[d[k][1]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][8]][a]-gamma[d[k][7]][a]-gamma[d[k][9]][a])*t2/2)*(e[a][0]-u[k][0]);
	
			dgamma[k][a]+=((gamma[d[k][2]][a]-gamma[d[k][3]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][7]][a]-gamma[d[k][8]][a]-gamma[d[k][9]][a])*t2/2)*(e[a][1]-u[k][1]);
	
			}
			}
			else
			{
				if(dimensions==2)
				{
					
					if(mask[d[k][0]]==0)
					{
						dgamma[k][a]=((gamma[d[k][2]][a]-gamma[d[k][3]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][7]][a]-gamma[d[k][8]][a]-gamma[d[k][9]][a])*t2/2)*(e[a][1]-u[k][1]);
					}
					
					if(mask[d[k][1]]==0)
					{
						dgamma[k][a]=((gamma[d[k][2]][a]-gamma[d[k][3]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][7]][a]-gamma[d[k][8]][a]-gamma[d[k][9]][a])*t2/2)*(e[a][1]-u[k][1]);
					}
					
					if(mask[d[k][2]]==0)
					{
						dgamma[k][a]=((gamma[d[k][0]][a]-gamma[d[k][1]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][8]][a]-gamma[d[k][7]][a]-gamma[d[k][9]][a])*t2/2)*(e[a][0]-u[k][0]);
					}
					
					if(mask[d[k][3]]==0)
					{
						dgamma[k][a]=((gamma[d[k][0]][a]-gamma[d[k][1]][a])*t1/2+(gamma[d[k][6]][a]+gamma[d[k][8]][a]-gamma[d[k][7]][a]-gamma[d[k][9]][a])*t2/2)*(e[a][0]-u[k][0]);
					}
				}
			}
			geq[k][a]=rho[k]*gamma[k][a]*cs2+(p[k]-rho[k]*cs2)*t[a]+(C[k]*mu[k]/cs2-rho[k])*dgamma[k][a];
	
	
			for(i=0;i<dimensions;i++)
			{	
				geq[k][a]-=(e[a][i]-u[k][i])*((gamma[k][a]-t[a])*drho[k][i]-C[k]*gamma[k][a]/cs2*dmu[k][i]);
			}

		
		}
	}
	}
}