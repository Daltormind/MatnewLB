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
	  if(yk<30 ){C[k]=1.0;}
	  else if (yk<60)
	  
	  {
	  			test=tanh(2.0*(45-yk)/ep);
				C[k]=0.5 + 0.5*test;  	
	  					}
	  					else if(yk>150)
	  					{
	  						test=tanh(2.0*(yk-165)/ep);
				C[k]=0.5 + 0.5*test; 
	  					}
	  
	  else {C[k]=0.0;}
		*/
		
		u[k][0]=ux;
		u[k][1]=uy;
		u[k][2]=uz;
		
	}
	
	
	
	}
	}

	for(k=k1;k<k2;++k)//Initialise free energy and density
	{
		if(mask[k]!=28)
		{

            if (mask[k]==0)
            {
            //d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+4.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/(6.0*dt*dt);
			            d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+C[d[k][10]]+C[d[k][11]]+C[d[k][12]]+C[d[k][13]]+C[d[k][14]]+C[d[k][15]]+C[d[k][16]]+C[d[k][17]]+2.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]]+C[d[k][4]]+C[d[k][5]])-24.0*C[k])/(6.0*dt*dt);

			}
			
		
			
	else if(mask[k]==1)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][7]] + C[d[k][9]] + 4.0*C[d[k][1]] - 6.0*dC + 2.0*C[d[k][2]] + 2.0*C[d[k][3]]-10.0*C[k])/(3.0*dt*dt);

	}
	else if(mask[k]==2)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][6]]+C[d[k][8]]+4.0*C[d[k][1]] + 2.0*C[d[k][2]] + 2.0*C[d[k][3]]-10.0*C[k] -6.0*dC )/(3.0*dt*dt);

	}
	else if(mask[k]==3)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][8]]+C[d[k][9]]+4.0*C[d[k][3]] + 2.0*C[d[k][0]] + 2.0*C[d[k][1]]-10.0*C[k] -6.0*dC )/(3.0*dt*dt);

	}
	else if(mask[k]==4)
	{
		dC=Wc*(C[k]-C[k]*C[k]);
		d2C=(C[d[k][6]]+C[d[k][7]]+4.0*C[d[k][2]] + 2.0*C[d[k][0]] + 2.0*C[d[k][1]]-10.0*C[k] -6.0*dC )/(3.0*dt*dt);

	}
	else if(mask[k]==7)
	{
	dC=Wc*(C[k]-C[k]*C[k]);
	d2C=1.0/6.0*(C[d[k][8]] + 2.0*C[d[k][9]] + C[d[k][7]]+ 4.0*C[d[k][3]] + 4.0*C[d[k][2]]
	+4.0*C[d[k][0]] + 4.0*C[d[k][1]] - 20.0*C[k]);
	}	
	else if(mask[k]==8)
	{
	dC=Wc*(C[k]-C[k]*C[k]);
	d2C=1.0/6.0*(C[d[k][6]] + 2.0*C[d[k][8]] + C[d[k][9]]+ 4.0*C[d[k][3]] + 4.0*C[d[k][2]]
	+4.0*C[d[k][0]] + 4.0*C[d[k][1]] - 20.0*C[k]);
	}	
	else if(mask[k]==9)
	{
	dC=Wc*(C[k]-C[k]*C[k]);
	d2C=1.0/6.0*(C[d[k][6]] + 2.0*C[d[k][7]] + C[d[k][79]]+ 4.0*C[d[k][3]] + 4.0*C[d[k][2]]
	+4.0*C[d[k][0]] + 4.0*C[d[k][1]] - 20.0*C[k]);
	}	
	else if(mask[k]==10)
	{
	dC=Wc*(C[k]-C[k]*C[k]);
	d2C=1.0/6.0*(C[d[k][8]] + 2.0*C[d[k][6]] + C[d[k][7]]+ 4.0*C[d[k][3]] + 4.0*C[d[k][2]]
	+4.0*C[d[k][0]] + 4.0*C[d[k][1]] - 20.0*C[k]);
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

	p[k]=g[k][0]+g[k][1]+g[k][2]+g[k][3]+g[k][4]+g[k][7]+g[k][8]+g[k][9]+g[k][10]+g[k][11]+g[k][12]+g[k][12]+g[k][13]+g[k][14]+g[k][15]+g[k][16]+g[k][17]+g[k][18]+g[k][5]+g[k][6]+dt*u[k][0]*gradrhoCx/6.0+dt*gradrhoCy*u[k][1]/6.0+dt*gradrhoCz*u[k][2]/6.0;//compute pressure

tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2);



}

}




}
