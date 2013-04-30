//Initialise variables

#include "wet.h"


void wet::initialise()
{

	ProcessN=Lx*Ly*Lz;
	cs2=1.0/3.0;//108900.0;//1.0/3.0;
	dt=1.0;
	dx=1.0;
	kappa=B*ep*ep/8;
	
	if(dimensions==2)
	{
		t0=4.0/9.0,t1=1.0/9.0,t2=1.0/36.0; //Weightings
		
		
	}	
	if(dimensions==3)
	{
		t0=1.0/3.0,t1=1.0/18.0,t2=1.0/36.0; //Weightings
		
	}	
	
	if(dimensions==1)
	{
		t0=2.0/3.0, t1=1.0/6.0;
	}	
	
	Q=19;
	
	d=new int[ProcessN][18]; //Array which holds neigbour values
	
	C=new double[ProcessN]; //Array which holds Composition values
	
	mask =new double[ProcessN]; //Array which holds the information on the substrate
	
	dC=new double[ProcessN][3];	//Array which holds gradient of composition
	
	u=new double[ProcessN][3]; //Velocity
	
	mu=new double[ProcessN]; //Free Energy
	
	dmu=new double[ProcessN][3];
	
	gamma=new double[ProcessN][19];//Gamma
	
	dgamma= new double[ProcessN][19];
	
	p=new double[ProcessN];//Pressure
	
	dp=new double[ProcessN][3];
	
	rho=new double[ProcessN];//Density
	
	drho=new double[ProcessN][3];
	
	geq=new double[ProcessN][19];
	
	heq=new double[ProcessN][19];
	
	g=new double[ProcessN][19];//
	
	h=new double[ProcessN][19];
	
	tau=new double[ProcessN];
	 
	gamhold=new double[ProcessN][19]; 
	
	hc=new double[ProcessN][19];
	
	gc=new double[ProcessN][19];
	
	f=new double[ProcessN];
	
	ht=new double[ProcessN][19];
	
	Ct=new double[ProcessN];
	
	//--------------------Initialise Variable values----------------------
	
	
	
	
	 
	
	 k1=0, k2=ProcessN;
	
	
	neibour();
	initialisesurface();
	
	
	
	relabel();
	
	initialisemoments();
	
	
	writemoments(0);
	
		
		
		
	
		
		equiliberiumg();
		
		
		equiliberiumh();
		writemoments(75);	
		
		
	for(k=k1;k<k2;k++)
	{	
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

	writevelocity(0);

}