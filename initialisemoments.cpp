//Initialise moments sets values of initial moments from starting values

#include "wet.h"

void wet::initialisemoments()
{
	
	
	//Initialise C Composition
	for(k=k1;k<k2;++k)
	{
	if(mask[k]!=28)
	{
	computecoordinates(k);
	
	if(R!=-1)
	{
	
	if((xk-xcentre)*(xk-xcentre)+(yk-ycentre)*(yk-ycentre)+(zk-zcentre)*(zk-zcentre)<R*R/*xk<50*/)
		{
			C[k]=1;
			u[k][0]=ux;
			u[k][1]=uy;
			u[k][2]=uz;
		
		}
	else
		{
		
			C[k]=0;
			u[k][0]=0.0;
			u[k][1]=0.0;
			u[k][2]=0.0;
		
		}
	}
	
	
	else
	{
		if(xk<=xcentre){C[k]=0;}else{C[k]=1;}
		u[k][0]=0.0;
		u[k][1]=0.0;
		u[k][2]=0.0;
	}	
	}
	}
		
	for(k=k1;k<k2;++k)
	{	
		if(mask[k]!=28)
		{	
			d2C=0.0;
			if(mask[k]==0 or mask[k]==2)
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
				if(mask[d[k][0]]==28)
				{
					d2C=2*( t1*( 2*C[d[k][1]] + C[d[k][2]] + C[d[k][3]] - 4*C[k] ) +2*t2*( C[d[k][7]] + C[d[k][9]] - 2*C[k] ));
				}
				if(mask[d[k][1]]==28)
				{
					d2C=2*( t1*( 2*C[d[k][0]]+ C[d[k][2]] + C[d[k][3]] - 4*C[k]) + 2*t2*( C[d[k][5]] + C[d[k][8]] - 2*C[k] ));
				}
				if(mask[d[k][2]]==28)
				{
					d2C=2*( t1*( 2*C[d[k][3]]+ C[d[k][0]] + C[d[k][1]] - 4*C[k]) + 2*t2*( C[d[k][8]] + C[d[k][9]] - 2*C[k] ));
				}
				if(mask[d[k][3]]==28)
				{
					d2C=2*( t1*( 2*C[d[k][2]]+ C[d[k][0]] + C[d[k][1]] - 4*C[k]) + 2*t2*( C[d[k][5]] + C[d[k][7]] - 2*C[k] ));
				}
				if(mask[d[k][6]]==28)
				{
					d2C=2*( t1*( C[d[k][2]] + C[d[k][3]]+ C[d[k][0]] + C[d[k][1]] - 4*C[k]) + t2*( C[d[k][8]] + 2*C[d[k][9]] +C[d[k][7]] - 4*C[k]) );
				}
				if(mask[d[k][7]]==28)
				{
					d2C=2*( t1*( C[d[k][2]] + C[d[k][3]]+ C[d[k][0]] + C[d[k][1]] - 4*C[k]) + t2*( 2*C[d[k][8]] + C[d[k][9]] +C[d[k][6]] - 4*C[k]) );
				}
				if(mask[d[k][8]]==28)
				{
					d2C=2*( t1*( C[d[k][2]] + C[d[k][3]]+ C[d[k][0]] + C[d[k][1]] - 4*C[k]) + t2*( 2*C[d[k][7]] + C[d[k][9]] +C[d[k][6]] - 4*C[k]) );
				}
				if(mask[d[k][9]]==28)
				{
					d2C=2*( t1*( C[d[k][2]] + C[d[k][3]]+ C[d[k][0]] + C[d[k][1]] - 4*C[k]) + t2*( 2*C[d[k][6]] + C[d[k][7]] +C[d[k][8]] - 4*C[k]) );
				}
			}
		
	
			mu[k]=/*2*B*( C[k]*pow(C[k]-1.0,2) + pow(C[k],2)*(C[k]-1.0) ) - kappa*( 1/(dt*dt) )*/d2C;
	
		}
	}
	
	for(k=k1;k<k2;++k)
	{
	if(mask[k]!=28)
	{
	if(mask[k]==0 or mask[k]==2)
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
			if(mask[d[k][0]])
			{
				dmu[k][0]=0.0;
				
				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]+mu[d[k][7]]-mu[d[k][8]]-mu[d[k][9]])*t2/2;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][1]])
			{
				dmu[k][0]=0.0;
				
				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]+mu[d[k][7]]-mu[d[k][8]]-mu[d[k][9]])*t2/2;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][2]])
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]+mu[d[k][8]]-mu[d[k][7]]-mu[d[k][9]])*t2/2;
				
				dmu[k][1]=0.0;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][3]])
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]+mu[d[k][8]]-mu[d[k][7]]-mu[d[k][9]])*t2/2;
				
				dmu[k][1]=0.0;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][6]])
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][8]]-mu[d[k][7]])*t2/2;

				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][7]]-mu[d[k][8]])*t2/2;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][7]])
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]-mu[d[k][9]])*t2/2;

				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]-mu[d[k][9]])*t2/2;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][8]])
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][6]]-mu[d[k][9]])*t2/2;

				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][6]]-mu[d[k][9]])*t2/2;

				dmu[k][2]=0.0;
			}
			
			if(mask[d[k][9]])
			{
				dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])*t1/2+(mu[d[k][8]]-mu[d[k][7]])*t2/2;

				dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])*t1/2+(mu[d[k][7]]-mu[d[k][8]])*t2/2;

				dmu[k][2]=0.0;
			}
		}
	}
	
	for(a=0;a<19;a++)
	{
		gamma[k][a]=t[a]*(1+(e[a][0]*u[k][0]+e[a][1]*u[k][1]+e[a][2]*u[k][2])/cs2+pow(e[a][0]*u[k][0]
		+e[a][1]*u[k][1]+e[a][2]*u[k][2],2)/cs2/cs2/2-(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/cs2/2);
		
		
	}
	
	
	rho[k]=C[k]*rho1+(1-C[k])*rho2;
	}
	}
	
	for(k=k1;k<k2;++k)
	{
	
	if(mask[k]!=28)
	{
	if(mask[k]==0 or mask[k]==2)
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
		if(mask[d[k][0]])
			{
				drho[k][0]=0.0;
				
				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]+rho[d[k][7]]-rho[d[k][8]]-rho[d[k][9]])*t2/2;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][1]])
			{
				drho[k][0]=0.0;
				
				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]+rho[d[k][7]]-rho[d[k][8]]-rho[d[k][9]])*t2/2;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][2]])
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]+rho[d[k][8]]-rho[d[k][7]]-rho[d[k][9]])*t2/2;
				
				drho[k][1]=0.0;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][3]])
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]+rho[d[k][8]]-rho[d[k][7]]-rho[d[k][9]])*t2/2;
				
				drho[k][1]=0.0;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][6]])
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][8]]-rho[d[k][7]])*t2/2;

				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][7]]-rho[d[k][8]])*t2/2;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][7]])
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]-rho[d[k][9]])*t2/2;

				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]-rho[d[k][9]])*t2/2;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][8]])
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][6]]-rho[d[k][9]])*t2/2;

				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][6]]-rho[d[k][9]])*t2/2;

				drho[k][2]=0.0;
			}
			
			if(mask[d[k][9]])
			{
				drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])*t1/2+(rho[d[k][8]]-rho[d[k][7]])*t2/2;

				drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])*t1/2+(rho[d[k][7]]-rho[d[k][8]])*t2/2;

				drho[k][2]=0.0;
			}
	}
	}
	p[k]=rho[k]*(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2;

tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2);

f[k]=0.0;
for(a=0;a<19;a++)
{
	f[k]+=gamma[k][a];
}
}

}




}