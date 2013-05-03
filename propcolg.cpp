//Propogation and collision of g

#include "wet.h"

void wet::propcolg()
{
	double ghold;
	
	for(k=k1;k<k2;k++)
	{	
		if(mask[k]!=28)
		{
	
		for(a=0 ;a<Q;a++)
		{
	
			diffMDgamma();
			ghold=g[k][a]-1/(tau[k]+0.5)*(g[k][a]-geq[k][a]);
			
	
			//ghold+=(rho[k]-C[k]*mu[k]/cs2)*dgammat[i];
			diffMDt(rho,drhot);
			diffMDt(mu,dmut);
			
	
			for(i=0;i<dimensions;i++)
			{
					ghold+=(e[a][i]-u[k][i])*((rho[k]*cs2-C[k]*mu[k])*dgammat[i]+(gamma[k][a]-t[a])*drhot[i]*cs2-C[k]*gamma[k][a]*dmut[i]);
			}
			
			if(mask[k]==1)
			{
				if(a==0)
				{
					gc[k][a]=ghold;
				}
				else
				{
					if(mask[d[k][a-1]]==28){gc[k][com[a]-1]=ghold;}else{gc[d[k][a-1]][a]=ghold;}		
				}
			}
			else
			{	
			if(a==0)
			{
				gc[k][a]=ghold;
			}
			else
			{
				gc[d[k][a-1]][a]=ghold;		
			}
			}
		

		}

		}
	}
}