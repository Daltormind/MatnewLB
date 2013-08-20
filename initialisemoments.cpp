//Initialise moments sets values of initial moments from starting values

#include "wet.h"

void wet::initialisemoments()
{

	double test,num;
	//Initialise C Composition
	for(k=k1;k<k2;++k)
	{
	if(mask[k]!=28)
	{
	computecoordinates(k);

	if(R!=-1)
	{

	if((xk-xcentre)*(xk-xcentre)+(yk-ycentre)*(yk-ycentre)+(zk-zcentre)*(zk-zcentre)<(R-3*ep)*(R-3*ep))
		{
			//C[k]=0.5+0.5*tanh(double(xk-25)/2/ep);//1;
			C[k]=1.0;//(1.0)/2.0+(1.0)/2.0*tanh(2.0/ep*(sqrt((xk-50.0)*(xk-50.0)+(yk-50.0)*(yk-50.0))-25.0));
			//rho[k]=rho1;
			u[k][0]=ux;
			u[k][1]=uy;
			u[k][2]=uz;

		}
		
		else if ((xk-xcentre)*(xk-xcentre)+(yk-ycentre)*(yk-ycentre)+(zk-zcentre)*(zk-zcentre)<(R+3*ep)*(R+3*ep))
		{
				
				num=sqrt((xk-xcentre)*(xk-xcentre)+(yk-ycentre)*(yk-ycentre)+(zk-zcentre)*(zk-zcentre));
				test=tanh(2.0*(ep/2.0-num+R)/ep);
				C[k]=0.5 + 0.5*test;
				u[k][0]=ux;
				u[k][1]=uy;
				u[k][2]=uz;
				
				//cout << "Entered boundry layer C=" << C[k]  << " test=" << test << " num=" << num << endl;
		
		}
		
	else
		{

			//C[k]=0.5+0.5*tanh(double(75-xk)/2/ep);
			C[k]=0.0;//(1.0)/2.0+(1.0)/2.0*tanh(2.0/ep*(sqrt((xk-50.0)*(xk-50.0)+(yk-50.0)*(yk-50.0))-25.0));
			//rho[k]=rho2;
			u[k][0]=ux;//double(xk)/10000;
			u[k][1]=uy;
			u[k][2]=uz;
		
	

		}
	}


	else
	{
	  
	  C[k]=0.0;
	  /*
	  if(xk<30 ){C[k]=1.0;}
	  else if (xk<60)
	  
	  {
	  			test=tanh(2.0*(45-xk)/ep);
				C[k]=0.5 + 0.5*test;  	
	  					}
	  					else if(xk>70)
	  					{
	  						test=tanh(2.0*(xk-85)/ep);
				C[k]=0.5 + 0.5*test; 
	  					}
	  
	  else {C[k]=0.0;}
		
		*/
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

            d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+4.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/(6.0*dt*dt);
			
			
		
			
	if(mask[k]==1)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][7]]-2*dC+C[d[k][7]]+C[d[k][9]]-2*dC+C[d[k][9]]+4.0*(C[d[k][1]]-2*dC+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/(6.0*dt*dt);

	}
	if(mask[k]==2)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][6]]+C[d[k][6]]-2*dC+C[d[k][8]]+C[d[k][8]]-2*dC+4.0*(C[d[k][1]]-2*dC+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/(6.0*dt*dt);

	}
			
			mu[k]=2*B*( C[k]*pow(C[k]-1.0,2) + pow(C[k],2)*(C[k]-1.0) ) - kappa*d2C;

            rho[k]=C[k]*rho1+(1-C[k])*rho2;
            
            //d2rho=(rho[d[k][6]]+rho[d[k][7]]+rho[d[k][8]]+rho[d[k][9]]+4.0*(rho[d[k][0]]+rho[d[k][1]]+rho[d[k][2]]+rho[d[k][3]])-20.0*rho[k])/6.0;
            
            //mu[k]=0.0;//4.0*B*(rho[k]-rho1)*(rho[k]-rho2)*(rho[k]-(rho2+rho1)*0.5)-kappa*d2rho; 
            
            if(C[k]<0)
			{
			muh[k]=mu[k]+2*BA*C[k];
			}
			else{muh[k]=mu[k];}
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
