//Initialise variables

#include "wet.h"


void wet::initialise()
{
	/*
	MPI_Status statusLeft, statusRight;

	//periodic boundary condition in processors
	if(rank==0)
		leftProcess=size-1;
	else
		leftProcess=rank-1;
	
	if(rank==size-1)
		rightProcess=0;
	else
		rightProcess=rank+1;
	cout << "Initialise: Process " << rank << " : rightProcess: " << rightProcess << " leftProcess: " << leftProcess << endl;


	N=Lx*Ly*Lz;
	
	if(size>LX)
	{
		cout << "Process " << rank << ": ERROR, too many processes for this lattice. Abort!" << endl;
		MPI_Abort(MPI_COMM_WORLD, 112);
	}

	if(size > (int)(LX/3))
		cout << "Process "<< rank <<": WARNING, very large number of processes for this lattice" << endl; 

	if(rank==ROOT)
		ProcessN=LY*LZ*((LX-LX%size)/size + LX%size + 4);	//Number of YZ plane for root process plus neighboors
	else
		ProcessN=LY*LZ*((LX-LX%size)/size+4);			    //Number of YZ plane for other processes

	k1 = 2*LY*LZ;			//k where real lattice starts
	k2 = ProcessN-2*LY*LZ;		//k where real lattice ends
	
	//Setting up different processors done.
	*/
	
	N=Lx*Ly*Lz;
	
	k1 = 0;			//k where real lattice starts
	k2 = N;		//k where real lattice ends
	
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






	
	 
	 Wc=-cos(theta*M_PI/180.0)*sqrt(2*B/kappa);


	neibour();
	initialisesurface();

	

	//relabel();

	initialisemoments();

	//momentsbound();
	
	writemoments(0);






		//equiliberiumg();
		

		//equiliberiumh();
		//writemoments(75);


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
		
		g[k][5]=geq5;
		g[k][6]=geq6;
		g[k][11]=geq11;
		g[k][12]=geq12;
		g[k][13]=geq13;
		g[k][14]=geq14;
		g[k][15]=geq15;
		g[k][16]=geq16;
		g[k][17]=geq17;
		g[k][18]=geq18;
		
		h[k][0]=heq0;
		h[k][1]=heq1;
		h[k][2]=heq2;
		h[k][3]=heq3;
		h[k][4]=heq4;

		h[k][7]=heq7;
		h[k][8]=heq8;
		h[k][9]=heq9;
		h[k][10]=heq10;
		
		h[k][5]=heq5;
		h[k][6]=heq6;
		h[k][11]=heq11;
		h[k][12]=heq12;
		h[k][13]=heq13;
		h[k][14]=heq14;
		h[k][15]=heq15;
		h[k][16]=heq16;
		h[k][17]=heq17;
		h[k][18]=heq18;
		/*
		f[k][0]=feq0;
		f[k][1]=feq1;
		f[k][2]=feq2;
		f[k][3]=feq3;
		f[k][4]=feq4;

		f[k][7]=feq7;
		f[k][8]=feq8;
		f[k][9]=feq9;
		f[k][10]=feq10;
		*/

		



	}
	
	

	writevelocity(0);

}
