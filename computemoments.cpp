//Computemoments


#include "wet.h"

void wet::computemoments()
{

double rh;

//Compute Composition C
for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{
		C[k]=0.0;
		p[k]=0.0;
		Ct[k]=0.0;

		
		for(a=0;a<Q;a++)
		{
			C[k]+=h[k][a];
			Ct[k]+=ht[k][a];
		}
		
		
}
}


//Compute free energy and density
for(k=k1;k<k2;k++)
{	
	if(mask[k]!=28)
{
	d2C=0.0;
	
	if(mask[k]==0)
	{
	for(a=1;a<Q;a++)
		{
			//d2C+=t[a]*(C[d[k][a-1]]-2*C[k]+C[d[k][com[a]-1]]);
			if(dimensions==1)
					{
					d2C=C[d[k][0]]-2*C[k]+C[d[k][1]];
					}
			
		}
	}
	else
	{
		if(dimensions==2)
		{
			if(mask[d[k][0]]==28)
			{
				d2C=2/cs2*( t1*( 2*C[d[k][1]] + C[d[k][2]] + C[d[k][3]] - 4*C[k] ) + t2*( C[d[k][6]] + C[d[k][7]] + C[d[k][8]] + C[d[k][9]] - 4*C[k])  );
			}
			
			if(mask[d[k][1]]==28)
			{
				d2C=2/cs2*( t1*( 2*C[d[k][0]] + C[d[k][2]] + C[d[k][3]] - 4*C[k] ) + t2*( C[d[k][6]] + C[d[k][7]] + C[d[k][8]] + C[d[k][9]] - 4*C[k])  );

			}
			
			if(mask[d[k][2]]==28)
			{
				d2C=2/cs2*( t1*( 2*C[d[k][3]] + C[d[k][0]] + C[d[k][1]] - 4*C[k] ) + t2*( C[d[k][6]] + C[d[k][7]] + C[d[k][8]] + C[d[k][9]] - 4*C[k])  );

			}
			
			if(mask[d[k][3]]==28)
			{
				d2C=2/cs2*( t1*( 2*C[d[k][2]] + C[d[k][0]] + C[d[k][1]] - 4*C[k] ) + t2*( C[d[k][6]] + C[d[k][7]] + C[d[k][8]] + C[d[k][9]] - 4*C[k])  );

			}
		}	
	}
	mu[k]=2*B*(C[k]*pow(C[k]-1.0,2)+pow(C[k],2)*(C[k]-1.0))-kappa*(1.0/(dt*dt))*d2C;
	
	
	rho[k]=C[k]*rho1+(1-C[k])*rho2;
}
}






//Compute Macroscopic velocity
for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{
if(mask[k]==0)
{
if(dimensions==3)
{
dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]+mu[d[k][8]]+mu[d[k][14]]+mu[d[k][16]]-mu[d[k][7]]-mu[d[k][9]]-mu[d[k][15]]-mu[d[k][17]])*t2/2;

dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]+mu[d[k][7]]+mu[d[k][10]]+mu[d[k][12]]-mu[d[k][8]]-mu[d[k][9]]-mu[d[k][11]]-mu[d[k][13]])*t2/2;

dmu[k][2]=(mu[d[k][4]]-mu[d[k][5]])*t1/2+(mu[d[k][10]]+mu[d[k][11]]+mu[d[k][14]]+mu[d[k][15]]-mu[d[k][12]]-mu[d[k][13]]-mu[d[k][16]]-mu[d[k][17]])*t2/2;
}
if(dimensions==2)
{
dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]+mu[d[k][8]]-mu[d[k][7]]-mu[d[k][9]])*t2/2;

dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]+mu[d[k][7]]-mu[d[k][8]]-mu[d[k][9]])*t2/2;

dmu[k][2]=0.0;
}
if(dimensions==1)
{
	dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2;
	
	dmu[k][1]=0.0;

	dmu[k][2]=0.0;
}
}
else
{
	if(dimensions==2)
		{
			if(mask[d[k][0]]==28)
			{
				dmu[k][0]=0.0;
				
				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]+mu[d[k][7]]-mu[d[k][8]]-mu[d[k][9]])*t2/2;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][1]]==28)
			{
				dmu[k][0]=0.0;
				
				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]+mu[d[k][7]]-mu[d[k][8]]-mu[d[k][9]])*t2/2;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][2]]==28)
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]+mu[d[k][8]]-mu[d[k][7]]-mu[d[k][9]])*t2/2;
				
				dmu[k][1]=0.0;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][3]]==28)
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]+mu[d[k][8]]-mu[d[k][7]]-mu[d[k][9]])*t2/2;
				
				dmu[k][1]=0.0;

				dmu[k][2]=0.0;
			}
		}
}	
	for(i=0;i<dimensions;i++)
	{
		u[k][i]=0.0;
		for(a=0;a<19;a++)
			{
				u[k][i]+=e[a][i]*g[k][a];
			
			

			}	
		
		
		u[k][i]-=C[k]*dmu[k][i];
		
		u[k][i]/=rho[k];
		u[k][i]/=cs2;	
		
		if(u[k][i]>0.5774)
		{
			//cout << "At st k i " << st << " " << k << " " << " " << i << " u is equal to " << u[k][i] << endl;
			 
		}
	}
}
}

//Compute macroscopic pressure
for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{
if(mask[k]==0)
{
if(dimensions==3)
{
drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]+rho[d[k][8]]+rho[d[k][14]]+rho[d[k][16]]-rho[d[k][7]]-rho[d[k][9]]-rho[d[k][15]]-rho[d[k][17]])*t2/2;

drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]+rho[d[k][7]]+rho[d[k][10]]+rho[d[k][12]]-rho[d[k][8]]-rho[d[k][9]]-rho[d[k][11]]-rho[d[k][13]])*t2/2;

drho[k][2]=(rho[d[k][4]]-rho[d[k][5]])*t1/2+(rho[d[k][10]]+rho[d[k][11]]+rho[d[k][14]]+rho[d[k][15]]-rho[d[k][12]]-rho[d[k][13]]-rho[d[k][16]]-rho[d[k][17]])*t2/2;
}
if(dimensions==2)
{
drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]+rho[d[k][8]]-rho[d[k][7]]-rho[d[k][9]])*t2/2;

drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]+rho[d[k][7]]-rho[d[k][8]]-rho[d[k][9]])*t2/2;

drho[k][2]=0.0;
}
if(dimensions==1)
{
	drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2;
	drho[k][1]=0.0;

	drho[k][2]=0.0;
}
}
else
{
if(dimensions==2)
		{
			if(mask[d[k][0]]==28)
			{
				drho[k][0]=0.0;
				
				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]+rho[d[k][7]]-rho[d[k][8]]-rho[d[k][9]])*t2/2;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][1]]==28)
			{
				drho[k][0]=0.0;
				
				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]+rho[d[k][7]]-rho[d[k][8]]-rho[d[k][9]])*t2/2;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][2]]==28)
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]+rho[d[k][8]]-rho[d[k][7]]-rho[d[k][9]])*t2/2;
				
				drho[k][1]=0.0;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][3]]==28)
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]+rho[d[k][8]]-rho[d[k][7]]-rho[d[k][9]])*t2/2;
				
				drho[k][1]=0.0;

				drho[k][2]=0.0;
			}
		}
}
	
	
	for(a=0;a<19;a++)
		{
			p[k]+=g[k][a];
		
		}

	p[k]+=drho[k][0]*u[k][0]+drho[k][1]*u[k][1]+drho[k][2]*u[k][2];
}
}
//Compute gamma

for(k=k1;k<k2;k++)
	{
	if(mask[k]!=28)
	{
		/*
		gamma[k][0]=t1/cs2*(1-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2);
		
		for(a=1;a<7;a++)
			{	
				gamma[k][a]=t1/cs2*(1+(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2])+pow(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2],2)/cs2/2-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2);
			
			
			}
	
	
		for(a=7;a<19;a++)
			{	
				gamma[k][a]=t2/cs2*(1+(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2])+pow(e[0][a]*u[k][0]+e[1][a]*u[k][1]+e[2][a]*u[k][2],2)/cs2/2-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2);
			
			
			}*/
		for(a=0;a<Q;a++)
		{
			gamma[k][a]=t[a]*(1+(e[a][0]*u[k][0]+e[a][1]*u[k][1]+e[a][2]*u[k][2])/cs2+pow(e[a][0]*u[k][0]
			+e[a][1]*u[k][1]+e[a][2]*u[k][2],2)/cs2/cs2/2-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/cs2/2);
		
		
		}
	
	
		tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2);
		
		f[k]=0;
		
		for(a=0;a<Q;a++)
		{
			f[k]+=gamma[k][a];
		}
	
	tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2);
	
	
	}
	}
	
}