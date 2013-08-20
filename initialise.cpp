//Initialise variables

#include "wet.h"


void wet::initialise()
{

	ProcessN=Lx*Ly*Lz;
	cs2=1.0/3.0;
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

	u=new double[ProcessN][3]; //Velocity

	mu=new double[ProcessN]; //Free Energy
	
	muh=new double[ProcessN];
	
	p=new double[ProcessN];//Pressure

	//drho=new double[ProcessN][3];

	rho=new double[ProcessN];//Density

	g=new double[ProcessN][19];//

	h=new double[ProcessN][19];
	
	gc=new double[ProcessN][19];//

	hc=new double[ProcessN][19];

	tau=new double[ProcessN];

	f=new double[ProcessN][19];

	

	//--------------------Initialise Variable values----------------------






	 k1=0, k2=ProcessN;
	 
	 Wc=-cos(theta*M_PI/180.0)*sqrt(2*B/kappa);


	neibour();
	initialisesurface();



	//relabel();

	initialisemoments();


	writemoments(0);






		//equiliberiumg();
		

		//equiliberiumh();
		writemoments(75);


	for(k=k1;k<k2;k++)
	{
        diffCD();
        diffBD();
        centralforce();
        equiliberiumg();
        equiliberiumh();
        equiliberiumf();

		g[k][0]=geq0;
		g[k][1]=geq1;
		g[k][2]=geq2;
		g[k][3]=geq3;
		g[k][4]=geq4;

		g[k][7]=geq7;
		g[k][8]=geq8;
		g[k][9]=geq9;
		g[k][10]=geq10;
		
		h[k][0]=heq0;
		h[k][1]=heq1;
		h[k][2]=heq2;
		h[k][3]=heq3;
		h[k][4]=heq4;

		h[k][7]=heq7;
		h[k][8]=heq8;
		h[k][9]=heq9;
		h[k][10]=heq10;
		
		f[k][0]=feq0;
		f[k][1]=feq1;
		f[k][2]=feq2;
		f[k][3]=feq3;
		f[k][4]=feq4;

		f[k][7]=feq7;
		f[k][8]=feq8;
		f[k][9]=feq9;
		f[k][10]=feq10;


		



	}

	writevelocity(0);

}
