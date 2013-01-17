//Computemoments


#include "wet.h"

void wet::computemoments()
{

double rh;

//Compute Composition C
for(k=k1;k<k2;k++){
C[k]=0;



for(a=0;a<Q;a++)
{
	C[k]+=h[k][a];
}

}

//Compute free energy and density
for(k=k1;k<k2;k++)
{	
	
	d2C=0.0;
	for(a=1;a<Q;a++)
		{
			d2C+=t[a]*(C[d[k][a-1]]-2*C[k]+C[d[k][com[a]-1]]);
			
		}
	
	mu[k]=2*B*(C[k]*pow(C[k]-1.0,2)+pow(C[k],2)*(C[k]-1.0))-kappa*(1.0/(cs2*dt*dt))*d2C;
	
	/*
	if(C[k]<0)
	{
		muh[k]=mu[k]+Ba*C[k];
	}
	else
	{
		muh[k]=mu[k];
	}
	*/
	rho[k]=C[k]*rho1+(1-C[k])*rho2;
}






//Compute Macroscopic velocity
for(k=k1;k<k2;k++)
{

	dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]+mu[d[k][8]]+mu[d[k][14]]+mu[d[k][16]]-mu[d[k][7]]-mu[d[k][9]]-mu[d[k][15]]-mu[d[k][17]])*t2/2;

dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]+mu[d[k][7]]+mu[d[k][10]]+mu[d[k][12]]-mu[d[k][8]]-mu[d[k][9]]-mu[d[k][11]]-mu[d[k][13]])*t2/2;

dmu[k][2]=(mu[d[k][4]]-mu[d[k][5]])*t1/2+(mu[d[k][10]]+mu[d[k][11]]+mu[d[k][14]]+mu[d[k][15]]-mu[d[k][12]]-mu[d[k][13]]-mu[d[k][16]]-mu[d[k][17]])*t2/2;
	
	
	for(i=0;i<2;i++)
	{
		u[k][i]=0;
		for(a=0;a<19;a++)
			{
				u[k][i]+=e[a][i]*g[k][a];
			
			

			}	
		
		
		u[k][i]+=C[k]*dmu[k][i];
		
		u[k][i]/=rho[k];
		u[k][i]/=cs2;	
	}
}

//Compute macroscopic pressure
for(k=k1;k<k2;k++)
{
	drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]+rho[d[k][8]]+rho[d[k][14]]+rho[d[k][16]]-rho[d[k][7]]-rho[d[k][9]]-rho[d[k][15]]-rho[d[k][17]])*t2/2;

drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]+rho[d[k][7]]+rho[d[k][10]]+rho[d[k][12]]-rho[d[k][8]]-rho[d[k][9]]-rho[d[k][11]]-rho[d[k][13]])*t2/2;

drho[k][2]=(rho[d[k][4]]-rho[d[k][5]])*t1/2+(rho[d[k][10]]+rho[d[k][11]]+rho[d[k][14]]+rho[d[k][15]]-rho[d[k][12]]-rho[d[k][13]]-rho[d[k][16]]-rho[d[k][17]])*t2/2;

	
	
	for(a=0;a<19;a++)
		{
			p[k]+=g[k][a];
		
		}

	p[k]+=drho[0][k]*u[k][0]+drho[1][k]*u[k][1]+drho[2][k]*u[k][2];
}

//Compute gamma

for(k=k1;k<k2;k++)
	{
		
		gamma[k][0]=t1/cs2*(1-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2);
		
		for(a=1;a<7;a++)
			{	
				gamma[k][a]=t1/cs2*(1+(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2])+pow(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2],2)/cs2/2-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2);
			
			
			}
	
	
		for(a=7;a<19;a++)
			{	
				gamma[k][a]=t2/cs2*(1+(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2])+pow(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2],2)/cs2/2-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2);
			
			
			}
	
	
	
	
	
	
	
	
	
	}
	
}