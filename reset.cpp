//reset resets all variables to 0 

#include "wet.h"

void wet::reset()
{
	for(k=k1;k<k2;k++)
	{
		C[k]=0.0;
	
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
	}









}