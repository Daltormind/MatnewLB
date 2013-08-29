
#include "wet.h"

void wet ::momentsbound()
{
	
	// Calculate values of C in boundry such that derivatives are satisfied.
	for(k=k1;k<k2;k++)
		{
		
		if(mask[k]!=28)
		{
			
			
			if(mask[k]==1)
			{
				//dC=Wc*(C[k]-C[k]*C[k]);
				C[d[k][0]]=C[d[k][1]];//-2*dC;
				C[d[d[k][0]][0]]=C[d[d[k][1]][1]];//+2*dC;
			}
			
			if(mask[k]==2)
			{
				//dC=Wc*(C[k]-C[k]*C[k]);
				C[d[k][1]]=C[d[k][0]];//-2*dC;
				C[d[d[k][1]][1]]=C[d[d[k][0]][0]];//+2*dC;
			}
		}
		}
		
	

	//calculate values of moments in boundary 
	
	for(k=k1;k<k2;k++)
	{
		if(mask[k]!=28)
		{
			
			
			if(mask[k]==1)
			{
				
				
				mu[d[k][0]]=mu[d[k][1]];
				mu[d[d[k][0]][0]]=mu[d[d[k][1]][1]];
				
				muh[d[k][0]]=muh[d[k][1]];
				muh[d[d[k][0]][0]]=muh[d[d[k][1]][1]];;
				
				rho[d[k][0]]=rho[d[k][1]];
				rho[d[d[k][0]][0]]=muh[d[d[k][1]][1]];
				
				p[d[k][0]]=p[d[k][1]];
				p[d[d[k][0]][0]]=p[d[d[k][1]][1]];
			}
			
			if(mask[k]==2)
			{
				
				mu[d[k][1]]=mu[d[k][0]];
				mu[d[d[k][1]][1]]=mu[d[d[k][0]][0]];
				
				muh[d[k][1]]=muh[d[k][0]];
				muh[d[d[k][1]][1]]=muh[d[d[k][0]][0]];
				
				rho[d[k][1]]=rho[d[k][0]];
				rho[d[d[k][1]][1]]=rho[d[d[k][0]][0]];
				
				p[d[k][1]]=p[d[k][0]];
				p[d[d[k][1]][1]]=p[d[d[k][0]][0]];
			}
		}
	}

}