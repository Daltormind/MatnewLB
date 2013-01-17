//Initialise moments sets values of initial moments from starting values

#include "wet.h"

void wet::initialisemoments()
{
	
	
	//Initialise C Composition
	for(i=k1;i<k2;++i)
	{
	computecoordinates(i);
	
	
	
	if((xk-xcentre)*(xk-xcentre)+(yk-ycentre)*(yk-ycentre)+(zk-zcentre)*(zk-zcentre)<R*R)
		{
			C[i]=1;
			u[i][0]=ux;
			u[i][1]=uy;
			u[i][2]=uz;
		
		}
	else
		{
		
			C[i]=0;
			u[i][0]=0.0;
			u[i][1]=0.0;
			u[i][2]=0.0;
		
		}
		
		}
		
	for(i=k1;i<k2;++i)
	{	
		d2C=0.0;
		for(a=1;a<19;a++)
		{
			d2C+=t[a]*(C[d[i][a-1]]-2*C[i]+C[d[i][com[a]-1]]);
					
			
		}
		
		
	
	mu[i]=2*B*(C[i]*pow(C[i]-1.0,2)+pow(C[i],2)*(C[i]-1.0))-kappa*(1/(cs2*dt*dt))*d2C;
	
	}
	
	for(i=k1;i<k2;++i)
	{
	
	dmu[i][0]=(mu[d[i][0]]-mu[d[i][1]])*t1/2+(mu[d[i][6]]+mu[d[i][8]]+mu[d[i][14]]+mu[d[i][16]]-mu[d[i][7]]-mu[d[i][9]]-mu[d[i][15]]-mu[d[i][17]])*t2/2;

	dmu[i][1]=(mu[d[i][2]]-mu[d[i][3]])*t1/2+(mu[d[i][6]]+mu[d[i][7]]+mu[d[i][10]]+mu[d[i][12]]-mu[d[i][8]]-mu[d[i][9]]-mu[d[i][11]]-mu[d[i][13]])*t2/2;

	dmu[i][2]=(mu[d[i][4]]-mu[d[i][5]])*t1/2+(mu[d[i][10]]+mu[d[i][11]]+mu[d[i][14]]+mu[d[i][15]]-mu[d[i][12]]-mu[d[i][13]]-mu[d[i][16]]-mu[d[i][17]])*t2/2;
	
	for(a=0;a<19;a++)
	{
		gamma[i][a]=t[a]*(1+(e[a][0]*u[i][0]+e[a][1]*u[i][1]+e[a][2]*u[i][2])/cs2+pow(e[a][0]*u[i][0]
		+e[a][1]*u[i][1]+e[a][2]*u[i][2],2)/cs2/cs2/2-(u[i][0]*u[i][0]+u[i][1]*u[i][1]+u[i][2]*u[i][2])/cs2/2);
		
		
	}
	
	
	rho[i]=C[i]*rho1+(1-C[i])*rho2;
	}
	
	
	for(i=k1;i<k2;++i)
	{
	drho[i][0]=(rho[d[i][0]]-rho[d[i][1]])*t1/2+(rho[d[i][6]]+rho[d[i][8]]+rho[d[i][14]]+rho[d[i][16]]-rho[d[i][7]]-rho[d[i][9]]-rho[d[i][15]]-rho[d[i][17]])*t2/2;

drho[i][1]=(rho[d[i][2]]-rho[d[i][3]])*t1/2+(rho[d[i][6]]+rho[d[i][7]]+rho[d[i][10]]+rho[d[i][12]]-rho[d[i][8]]-rho[d[i][9]]-rho[d[i][11]]-rho[d[i][13]])*t2/2;

drho[i][2]=(rho[d[i][4]]-rho[d[i][5]])*t1/2+(rho[d[i][10]]+rho[d[i][11]]+rho[d[i][14]]+rho[d[i][15]]-rho[d[i][12]]-rho[d[i][13]]-rho[d[i][16]]-rho[d[i][17]])*t2/2;
	
	p[i]=rho[i]*(u[i][0]*u[i][0]+u[i][1]*u[i][1]+u[i][2]*u[i][2])/2;

}




}