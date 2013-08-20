//Computemoments


#include "wet.h"

void wet::computemoments()
{



//Compute Composition C
for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{

		
		


		C[k]=h[k][0]+h[k][1]+h[k][2]+h[k][3]+h[k][4]+h[k][7]+h[k][8]+h[k][9]+h[k][10]; //Compute C from updated velocity distributions
		//rho[k]=f[k][0]+f[k][1]+f[k][2]+f[k][3]+f[k][4]+f[k][7]+f[k][8]+f[k][9]+f[k][10];
		rho[k]=C[k]*rho1+(1-C[k])*rho2; //Compute Rho from updated moments
		
		tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2); // Compute tau for updated moments
		
		

}
}

for(k=k1;k<k2;k++)//Initialise free energy 
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

            
            
            //d2rho=(rho[d[k][6]]+rho[d[k][7]]+rho[d[k][8]]+rho[d[k][9]]+4.0*(rho[d[k][0]]+rho[d[k][1]]+rho[d[k][2]]+rho[d[k][3]])-20.0*rho[k])/6.0;
            
            //mu[k]=0.0;//4.0*B*(rho[k]-rho1)*(rho[k]-rho2)*(rho[k]-(rho2+rho1)*0.5)-kappa*d2rho; 
            
            if(C[k]<0)
			{
			muh[k]=mu[k]+2*BA*C[k];
			}
			else{muh[k]=mu[k];}
		}
	}

//Compute Macroscopic velocity
for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{
            gradmuC1=0.5*(mu[d[k][0]]-mu[d[k][1]]);
			gradmuC2=0.5*(mu[d[k][1]]-mu[d[k][0]]);
    		gradmuC3=0.5*(mu[d[k][2]]-mu[d[k][3]]);
    		gradmuC4=0.5*(mu[d[k][3]]-mu[d[k][2]]);
    		gradmuC7=0.5*(mu[d[k][6]]-mu[d[k][9]]);
    		gradmuC8=0.5*(mu[d[k][7]]-mu[d[k][8]]);
    		gradmuC9=0.5*(mu[d[k][8]]-mu[d[k][7]]);
    		gradmuC10=0.5*(mu[d[k][9]]-mu[d[k][6]]);

    		gradmuCx=1.0/3.0*(gradmuC1-gradmuC2)+1.0/12.0*(gradmuC7-gradmuC8+gradmuC9-gradmuC10);
    		gradmuCy=1.0/3.0*(gradmuC3-gradmuC4)+1.0/12.0*(gradmuC7+gradmuC8-gradmuC9-gradmuC10);
    		
    		
			
			/*
			if(st<50)
			{
            u[k][0]=0.0;//(3.0*(g[k][1]-g[k][2]+g[k][7]-g[k][10]+g[k][9]-g[k][8])-0.5*C[k]*gradmuCx)/rho[k];
            u[k][1]=0.0;//(3.0*(g[k][3]-g[k][4]+g[k][7]-g[k][10]+g[k][8]-g[k][9])-0.5*C[k]*gradmuCy)/rho[k];
			}
			else
			{
				u[k][0]=(3.0*(g[k][1]-g[k][2]+g[k][7]-g[k][10]+g[k][9]-g[k][8])-0.5*C[k]*gradmuCx)/rho[k];
            	u[k][1]=(3.0*(g[k][3]-g[k][4]+g[k][7]-g[k][10]+g[k][8]-g[k][9])-0.5*C[k]*gradmuCy)/rho[k];
			}
			*/
			
			
			
			//u[k][0]=0.0;
			//u[k][1]=0.0;
			 u[k][0]=(3.0*(g[k][1]-g[k][2]+g[k][7]-g[k][10]+g[k][9]-g[k][8])+0.5*dt*mu[k]*gradCCx)/rho[k];
			 u[k][1]=(3.0*(g[k][3]-g[k][4]+g[k][7]-g[k][10]+g[k][8]-g[k][9])+0.5*dt*mu[k]*gradCCy)/rho[k];
			
			
			//u[k][0]=((f[k][1]-f[k][2]+f[k][7]-f[k][10]+f[k][9]-f[k][8])-0.5*rho[k]*gradmuCx+(1.0/6.0)*gradrhoCx)/rho[k];
            //u[k][1]=((f[k][3]-f[k][4]+f[k][7]-f[k][10]+f[k][8]-f[k][9])-0.5*rho[k]*gradmuCy+(1.0/6.0)*gradrhoCy)/rho[k];
}
}

//Compute macroscopic pressure

for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{

            gradrhoC1=0.5*(rho[d[k][0]]-rho[d[k][1]]);
			gradrhoC2=0.5*(rho[d[k][1]]-rho[d[k][0]]);
    		gradrhoC3=0.5*(rho[d[k][2]]-rho[d[k][3]]);
    		gradrhoC4=0.5*(rho[d[k][3]]-rho[d[k][2]]);
    		gradrhoC7=0.5*(rho[d[k][6]]-rho[d[k][9]]);
    		gradrhoC8=0.5*(rho[d[k][7]]-rho[d[k][8]]);
    		gradrhoC9=0.5*(rho[d[k][8]]-rho[d[k][7]]);
    		gradrhoC10=0.5*(rho[d[k][9]]-rho[d[k][6]]);
            gradrhoCx=1.0/3.0*(gradrhoC1-gradrhoC2)+1.0/12.0*(gradrhoC7-gradrhoC8+gradrhoC9-gradrhoC10);
    		gradrhoCy=1.0/3.0*(gradrhoC3-gradrhoC4)+1.0/12.0*(gradrhoC7+gradrhoC8-gradrhoC9-gradrhoC10);
	
	/*
	if(st<50)
	{
	p[k]=0.0;
    }
    
    else
    {
    p[k]=g[k][0]+g[k][1]+g[k][2]+g[k][3]+g[k][4]+g[k][7]+g[k][8]+g[k][9]+g[k][10]+u[k][0]*gradrhoCx/6.0+gradrhoCy*u[k][1]/6.0;
	}
    */
    
    //p[k]=0.0;
    
	p[k]=g[k][0]+g[k][1]+g[k][2]+g[k][3]+g[k][4]+g[k][7]+g[k][8]+g[k][9]+g[k][10]+dt*u[k][0]*gradrhoCx/6.0+dt*gradrhoCy*u[k][1]/6.0;//compute pressure
}
}





}



