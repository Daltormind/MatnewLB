//Computemoments


void wet::computemoments()
{

double d2C[k],dmu[k][3],drho[k],rh;

//Compute Composition C
for(k=ki;k<ke;k++){
C[k]=0;



for(a=0;a<19;a++)
{
	C+=h[a];
}

}

//Compute free energy and density
for(k=ki;k<ke;k++)
{	
	for(a=1;a<19;a++)
		{
			d2C+=t[a]*(C[d[k][a]]-2*C[k]-C[d[k][a1[a]]]);Needs changing
			
		}
	
	mu[k]=2*B(C*pow(C-1,2)+pow(C,2)*(C-1))-kappa*(1/(cs*cs*dt*dt))*d2C;
	
	if(C[k]<0)
	{
		muh[k]=mu[k]+Ba*C[k];
	}
	else
	{
		muh[k]=mu[k];
	}

	rho[k]=C[k]*rho1+(1-C)*rho2;
}






//Compute Macroscopic velocity
for(k=ki;k<ke;k++)
{

	dmu[k][0]=(mu[d[k][0]]-mu[d[k][1]])/t1/2+(mu[d[k][6]]+mu[d[k][8]]+mu[d[k][14]]+mu[d[k][16]]-mu[d[k][7]]-mu[d[k][9]]-mu[d[k][15]]-mu[d[k][17]])/t2/2;

dmu[k][1]=(mu[d[k][2]]-mu[d[k][3]])/t1/2+(mu[d[k][6]]+mu[d[k][7]]+mu[d[k][10]]+mu[d[k][12]]-mu[d[k][8]]-mu[d[k][9]]-mu[d[k][11]]-mu[d[k][13]])/t2/2;

dmu[k][2]=(mu[d[k][4]]-mu[d[k][5]])/t1/2+(mu[d[k][10]]+mu[d[k][11]]+mu[d[k][14]]+mu[d[k][15]]-mu[d[k][12]]-mu[d[k][13]]-mu[d[k][16]]-mu[d[k][17]])/t2/2;
	
	
	for(i=0;i<2;i++)
	{
		u[k][i]=0;
		for(a=0;a<19;a++)
			{
				u[k][i]+=e[i][a]*g[a];
			
			

			}	
		
		
		u[k][i]+=C[k]*dmu[k][i]);
		
		u[k][i]/=rho[k];
		u[k][i]/=cs2;	
	}
}

//Compute macroscopic pressure
for(k=ki;k<ke;k++)
{
	drho[k][0]=(rho[d[k][0]]-rho[d[k][1]])/t1/2+(rho[d[k][6]]+rho[d[k][8]]+rho[d[k][14]]+rho[d[k][16]]-rho[d[k][7]]-rho[d[k][9]]-rho[d[k][15]]-rho[d[k][17]])/t2/2;

drho[k][1]=(rho[d[k][2]]-rho[d[k][3]])/t1/2+(rho[d[k][6]]+rho[d[k][7]]+rho[d[k][10]]+rho[d[k][12]]-rho[d[k][8]]-rho[d[k][9]]-rho[d[k][11]]-rho[d[k][13]])/t2/2;

drho[k][2]=(rho[d[k][4]]-rho[d[k][5]])/t1/2+(rho[d[k][10]]+rho[d[k][11]]+rho[d[k][14]]+rho[d[k][15]]-rho[d[k][12]]-rho[d[k][13]]-rho[d[k][16]]-rho[d[k][17]])/t2/2;

	
	
	for(a=0;a<19;a++)
		{
			p[k]+=g[a];
		
		}

	p[k]+=drho[0][k]*u[k][0]+drho[1][k]*u[k][1]+drho[2][k]*u[k][2];
}

//Compute gamma

for(k=ki;k<ke;k++)
	{
		
		gamma[k][0]=t1/cs2*(1-(u[0]*u[0]+u[1]*u[1]+u[2]*u[2])/2);
		
		for(a=1;a<7;a++)
			{	
				gamma[k][a]=t1/cs2*(1+(e[0][a]*u[0]+e[1][a]*u[1]+e[2][a]*u[2])+pow(e[0][a]*u[0]+e[1][a]*u[1]+e[2][a]*u[2],2)/cs2/2-(u[0]*u[0]+u[1]*u[1]+u[2]*u[2])/2)
			
			
			}
	
	
		for(a=7;a<19;a++)
			{	
				gamma[k][a]=t2/cs2*(1+(e[0][a]*u[0]+e[1][a]*u[1]+e[2][a]*u[2])+pow(e[0][a]*u[0]+e[1][a]*u[1]+e[2][a]*u[2],2)/cs2/2-(u[0]*u[0]+u[1]*u[1]+u[2]*u[2])/2)
			
			
			}
	
	
	
	
	
	
	
	
	
	}