//propcolh

#include "wet.h"

void wet::propcolh()
{
	double hold;
	
	for(k=k1;k<k2;k++)
	{	if(mask[k]!=28)
		{
		for(a=0;a<Q;a++)
		{
			
			hold=0.0;
			
			if(st==1 and k==5000)
			{
				//cout << "Hold1=" << hold << "Heq k a= " << heq[k][a] << endl;
			}
			/*
			for(i=0;i<dimensions;i++)
			{
				//hold+=(e[a][i]-u[k][i])*(dC[k][i]/cs2-C[k]/rho[k]/cs2/cs2*(dp[k][i]+C[k]*dmu[k][i]))*gamma[k][a];
	
			}

			if(st==1 and k==5000 )
			{
				cout <<"a=" << a<< " Hold2=" << hold  << endl;
			}
			*/
			
			hold+=(e[a][0]-u[k][0])*(dC[k][0]-C[k]/rho[k]/cs2*(dp[k][0]+C[k]*dmu[k][0]));
	
		hold+=(e[a][1]-u[k][1])*(dC[k][1]-C[k]/rho[k]/cs2*(dp[k][1]+C[k]*dmu[k][1]));
	
		hold+=(e[a][2]-u[k][2])*(dC[k][2]-C[k]/rho[k]/cs2*(dp[k][2]+C[k]*dmu[k][2]));
	
		hold/=cs2;
	
		
	
		hold*=gamma[k][a];
		
		hold+=h[k][a]-1/(tau[k]+0.5)*(h[k][a]-heq[k][a]);
			
			if(mask[k]==1)
			{
				if(a==0)
				{
					hc[k][a]=hold;
				}
				else
				{
					if(mask[d[k][a-1]]==28){hc[k][com[a]-1]=hold;}else{hc[d[k][a-1]][a]=hold;}		
				}
			}
			else
			{
			if(a==0)
			{
				hc[k][a]=hold;
			}
			else
			{
				hc[d[k][a-1]][a]=hold;		
			}
			}
		}
	}
	}
}	