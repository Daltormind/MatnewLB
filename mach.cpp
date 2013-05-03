//Mach.cpp computes the mach number and the laplace operator terms for h propogation

#include "wet.h"

void wet::mach()
{
	for(k=k1;k<k2;k++)
	{
		
		
		
	
	for(a=0;a<Q;a++)
	{
	
	if(C[k]<0)
	{
		gamma[k][a]=(mu[k]+2*BA*C[k])*gamma[k][a];
		
		
		
	}
	else
	{
		gamma[k][a]=mu[k]*gamma[k][a];
		
	}
	
	gamhold[k][a]=0;
	}
	}
	for(k=k1;k<k2;k++)
	{
	
	for(a=0;a<Q;a++)
	{
	
	//for(int b=1;b<Q;b++)
		//{
			//gamhold[k][a]+=t[b]*(gamma[d[k][b-1]][a]-2*gamma[k][a]+gamma[d[k][com[b]-1]][a])/dt/cs2;
			if(dimensions==1)
			{
				gamhold[k][a]=gamma[d[k][0]][a]-2*gamma[k][a]+gamma[d[k][1]][a];
			}
			
		//}

		
	
	}
	}
	
	for(k=k1;k<k2;k++)
	{
		for(a=0;a<Q;a++)
		{
			if(a==0)
			{
				hc[k][a]+=M/2*(gamhold[k][a]+gamhold[k][a]);
				ht[k][a]+=M/2*(gamhold[k][a]+gamhold[k][a]);
			}
			else
			{	
				hc[k][a]+=M/2*(gamhold[d[k][com[a]-1]][a]+gamhold[k][a]);
				ht[k][a]+=M/2*(gamhold[d[k][com[a]-1]][a]+gamhold[k][a]);
			}
		
			h[k][a]=hc[k][a];
			g[k][a]=gc[k][a];
		
		}
	
		
	}
	
	
} 