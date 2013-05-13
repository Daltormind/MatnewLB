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

	for(k=k1;k<k2;++k)//Initialise free energy and density
	{
		if(mask[k]!=28)
		{

            d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+4.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/6.0

			mu[k]=2*B*( C[k]*pow(C[k]-1.0,2) + pow(C[k],2)*(C[k]-1.0) ) - kappa*( 1/(dt*dt) )*d2C;

            rho[k]=C[k]*rho1+(1-C[k])*rho2;
		}
	}




	for(k=k1;k<k2;++k)
	{

	if(mask[k]!=28)
	{

	p[k]=rho[k]*(u[k][0]*u[k][0]+u[k][1]*u[k][1]+u[k][2]*u[k][2])/2;

tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2);


}

}




}
