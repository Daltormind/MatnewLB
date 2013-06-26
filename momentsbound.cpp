
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
				dC=Wc*(C[k]-C[k]*C[k]);
				C[d[k][0]]=C[d[k][1]]-2*dC;
				C[d[d[k][0]][0]]=4*C[d[k][0]]-3*C[k]+2*dC;
			}
			
			if(mask[k]==2)
			{
				dC=Wc*(C[k]-C[k]*C[k]);
				C[d[k][1]]=C[d[k][0]]-2*dC;
				C[d[d[k][1]][1]]=4*C[d[k][1]]-3*C[k]+2*dC;
			}
		}
		}
		
	//Compute free energy and density
for(k=k1;k<k2;k++)
{
	if(mask[k]!=28)
{

	d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+4.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/6.0;
	
	/*
	if(mask[k]==1)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][7]]-2*dC+C[d[k][7]]+C[d[k][9]]-2*dC+C[d[k][9]]+4.0*(C[d[k][1]]-2*dC+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/6.0;

		
	}
	if(mask[k]==2)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][6]]+C[d[k][6]]-2*dC+C[d[k][8]]+C[d[k][8]]-2*dC+4.0*(C[d[k][1]]-2*dC+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/6.0;

		
	}
	*/
	mu[k]=2*B*(C[k]*pow(C[k]-1.0,2)+pow(C[k],2)*(C[k]-1.0))-kappa*(1.0/(dt*dt))*d2C;


	rho[k]=C[k]*rho1+(1-C[k])*rho2;
	
	// d2rho=(rho[d[k][6]]+rho[d[k][7]]+rho[d[k][8]]+rho[d[k][9]]+4.0*(rho[d[k][0]]+rho[d[k][1]]+rho[d[k][2]]+rho[d[k][3]])-20.0*rho[k])/6.0;
            
      //      mu[k]=4.0*B*(rho[k]-rho1)*(rho[k]-rho2)*(rho[k]-(rho2+rho1)*0.5)-kappa*d2rho; 
	
	if(C[k]<0)
	{
	muh[k]=mu[k]+2*BA*C[k];
	}
	else{muh[k]=mu[k];}
	
}
}

	//calculate values of mu and muh in boundary 
	
	for(k=k1;k<k2;k++)
	{
		if(mask[k]!=28)
		{
			
			
			if(mask[k]==1)
			{
				
				
				mu[d[k][0]]=mu[d[k][1]];
				mu[d[d[k][0]][0]]=4*mu[d[k][0]]-3*mu[k];
				
				muh[d[k][0]]=muh[d[k][1]];
				muh[d[d[k][0]][0]]=4*muh[d[k][0]]-3*muh[k];
				
				rho[d[k][0]]=rho[d[k][1]];
				rho[d[d[k][0]][0]]=4*rho[d[k][0]]-3*rho[k];
				
				p[d[k][0]]=p[d[k][1]];
				p[d[d[k][0]][0]]=4*p[d[k][0]]-3*p[k];
			}
			
			if(mask[k]==2)
			{
				
				mu[d[k][1]]=mu[d[k][0]];
				mu[d[d[k][1]][1]]=4*mu[d[k][1]]-3*mu[k];
				
				muh[d[k][1]]=muh[d[k][0]];
				muh[d[d[k][1]][1]]=4*muh[d[k][1]]-3*muh[k];
				
				rho[d[k][1]]=rho[d[k][0]];
				rho[d[d[k][1]][1]]=4*rho[d[k][1]]-3*rho[k];
				
				p[d[k][1]]=p[d[k][0]];
				p[d[d[k][1]][1]]=4*p[d[k][1]]-3*p[k];
			}
		}
	}

}