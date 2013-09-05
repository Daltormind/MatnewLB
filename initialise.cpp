//Initialise variables

#include "wet.h"


void wet::initialise()
{
	
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
	
	if(size>Lx)
	{
		cout << "Process " << rank << ": ERROR, too many processes for this lattice. Abort!" << endl;
		MPI_Abort(MPI_COMM_WORLD, 112);
	}

	if(size > (int)(Lx/3))
		cout << "Process "<< rank <<": WARNING, very large number of processes for this lattice" << endl; 

	if(rank==ROOT)
		ProcessN=Ly*Lz*((Lx-Lx%size)/size + Lx%size + 4);	//Number of YZ plane for root process plus neighboors
	else
		ProcessN=Ly*Lz*((Lx-Lx%size)/size+4);			    //Number of YZ plane for other processes

	k1 = 2*Ly*Lz;			//k where real lattice starts
	k2 = ProcessN-2*Ly*Lz;		//k where real lattice ends
	
	//Setting up different processors done.
	
	
	cout << "Entered initialise" << endl;
	
	/*
	N=Lx*Ly*Lz;
	ProcessN=N;
	k1 = 0;			//k where real lattice starts
	k2 = N;		//k where real lattice ends
	*/
	
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
	
	CGlobal=new double[N];
	
	maskGlobal=new double[N];

	d=new int[ProcessN][18]; //Array which holds neigbour values

	C=new double[ProcessN]; //Array which holds Composition values

	mask =new double[ProcessN]; //Array which holds the information on the substrate

	ux=new double[ProcessN]; uy=new double[ProcessN];uz=new double[ProcessN];//Velocity

	mu=new double[ProcessN]; //Free Energy
	
	muh=new double[ProcessN];
	
	p=new double[ProcessN];//Pressure

	//drho=new double[ProcessN][3];

	rho=new double[ProcessN];//Density

	g0=new double[ProcessN]; g1=new double[ProcessN]; g2=new double[ProcessN]; g3=new double[ProcessN]; g4=new double[ProcessN];
	g5=new double[ProcessN]; g6=new double[ProcessN]; g7=new double[ProcessN]; g8=new double[ProcessN]; g9=new double[ProcessN];
	g10=new double[ProcessN]; g11=new double[ProcessN]; g12=new double[ProcessN]; g13=new double[ProcessN]; g14=new double[ProcessN];
	g15=new double[ProcessN]; g16=new double[ProcessN]; g17=new double[ProcessN]; g18=new double[ProcessN];

	h0=new double[ProcessN]; h1=new double[ProcessN]; h2=new double[ProcessN]; h3=new double[ProcessN]; h4=new double[ProcessN];
	h5=new double[ProcessN]; h6=new double[ProcessN]; h7=new double[ProcessN]; h8=new double[ProcessN]; h9=new double[ProcessN];
	h10=new double[ProcessN]; h11=new double[ProcessN]; h12=new double[ProcessN]; h13=new double[ProcessN]; h14=new double[ProcessN];
	h15=new double[ProcessN]; h16=new double[ProcessN]; h17=new double[ProcessN]; h18=new double[ProcessN];

	hc0=new double[ProcessN]; hc1=new double[ProcessN]; hc2=new double[ProcessN]; hc3=new double[ProcessN]; hc4=new double[ProcessN];
	hc5=new double[ProcessN]; hc6=new double[ProcessN]; hc7=new double[ProcessN]; hc8=new double[ProcessN]; hc9=new double[ProcessN];
	hc10=new double[ProcessN]; hc11=new double[ProcessN]; hc12=new double[ProcessN]; hc13=new double[ProcessN]; hc14=new double[ProcessN];
	hc15=new double[ProcessN]; hc16=new double[ProcessN]; hc17=new double[ProcessN]; hc18=new double[ProcessN];

	gc0=new double[ProcessN]; gc1=new double[ProcessN]; gc2=new double[ProcessN]; gc3=new double[ProcessN]; gc4=new double[ProcessN];
	gc5=new double[ProcessN]; gc6=new double[ProcessN]; gc7=new double[ProcessN]; gc8=new double[ProcessN]; gc9=new double[ProcessN];
	gc10=new double[ProcessN]; gc11=new double[ProcessN]; gc12=new double[ProcessN]; gc13=new double[ProcessN]; gc14=new double[ProcessN];
	gc15=new double[ProcessN]; gc16=new double[ProcessN]; gc17=new double[ProcessN]; gc18=new double[ProcessN];
	tau=new double[ProcessN];

	//f=new double[ProcessN][19];

	

	//--------------------Initialise Variable values----------------------


	cout << "Initialised variables" << endl;



	
	 
	 Wc=-cos(theta*M_PI/180.0)*sqrt(2*B/kappa);


	neibour();
	initialisesurface();

	

	//relabel();

	initialisemoments();

	//momentsbound();
	
	writemoments(0);


	cout << "Initialised surface and moments" << endl;



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
        //equiliberiumf();

		g0[k]=geq0;
		g1[k]=geq1;
		g2[k]=geq2;
		g3[k]=geq3;
		g4[k]=geq4;

		g7[k]=geq7;
		g8[k]=geq8;
		g9[k]=geq9;
		g10[k]=geq10;
		
		g5[k]=geq5;
		g6[k]=geq6;
		g11[k]=geq11;
		g12[k]=geq12;
		g13[k]=geq13;
		g14[k]=geq14;
		g15[k]=geq15;
		g16[k]=geq16;
		g17[k]=geq17;
		g18[k]=geq18;
		
		h0[k]=heq0;
		h1[k]=heq1;
		h2[k]=heq2;
		h3[k]=heq3;
		h4[k]=heq4;

		h7[k]=heq7;
		h8[k]=heq8;
		h9[k]=heq9;
		h10[k]=heq10;
		
		h5[k]=heq5;
		h6[k]=heq6;
		h11[k]=heq11;
		h12[k]=heq12;
		h13[k]=heq13;
		h14[k]=heq14;
		h15[k]=heq15;
		h16[k]=heq16;
		h17[k]=heq17;
		h18[k]=heq18;
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
	
	

	//writevelocity(0);
	cout << "Finished initialise" << endl;
}
