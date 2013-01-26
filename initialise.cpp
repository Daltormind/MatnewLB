//Initialise variables

#include "wet.h"


void wet::initialise()
{

	ProcessN=Lx*Ly*Lz;
	cs2=1.0/3.0;
	dt=1.0;
	dx=1.0;
	
	
	d=new int[ProcessN][18]; //Array which holds neigbour values
	
	C=new double[ProcessN]; //Array which holds Composition values
	
	dC=new double[ProcessN][3];	//Array which holds gradient of composition
	
	u=new double[ProcessN][3]; //Velocity
	
	mu=new double[ProcessN]; //Free Energy
	
	dmu=new double[ProcessN][3];
	
	gamma=new double[ProcessN][19];//Gamma
	
	dgamma= new double[ProcessN][19];
	
	dgamma1= new double[ProcessN][19];
	
	p=new double[ProcessN];//Pressure
	
	dp=new double[ProcessN][3];
	
	rho=new double[ProcessN];//Density
	
	drho=new double[ProcessN][3];
	
	geq=new double[ProcessN][19];
	
	heq=new double[ProcessN][19];
	
	g=new double[ProcessN][19];//
	
	h=new double[ProcessN][19];
	
	
	
	//--------------------Initialise Variable values----------------------
	
	t0=1.0/3.0,t1=1.0/18.0,t2=1.0/36.0; //Weightings
	Q=19; // Number of velocity discridations
				
	 
	
	 k1=0, k2=ProcessN;
	
	for(k=k1;k<k2;++k)
	{
	neibour(k);
	}
	
	initialisemoments();
	
	for(k=k1;k<k2;++k)
	{
		
		
		
		
	
		
		equiliberiumg(k);
		
		
		equiliberiumh(k);
	
		//diffMD();
		
		for(a=0;a<Q;a++)
			{
				g[k][a]=geq[k][a];//+(rho[k]-C[k]*mu[k]/cs2)*dgamma[k][a];
				for(i=0;i<dimensions;i++)
				{
					//g[k][a]+=(e[a][i]-u[k][i])*((gamma[k][a]-t[a])*drho[k][i]-C[k]*gamma[k][a]*dmu[k][i]/cs2);
				}
				h[k][a]=heq[k][a]	;	
			}
	
	
	
	}

	

}