//Computemoments


#include "wet.h"

void wet::computemoments()
{



//Compute Composition C
for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{

		
		


		C[k]=h[k][0]+h[k][1]+h[k][2]+h[k][3]+h[k][4]+h[k][7]+h[k][8]+h[k][9]+h[k][10]+h[k][11]+h[k][12]+h[k][13]+h[k][14]+h[k][15]+h[k][16]+h[k][17]+h[k][18]+h[k][5]+h[k][6]; //Compute C from updated velocity distributions
		//rho[k]=f[k][0]+f[k][1]+f[k][2]+f[k][3]+f[k][4]+f[k][7]+f[k][8]+f[k][9]+f[k][10];
		rho[k]=C[k]*rho1+(1-C[k])*rho2; //Compute Rho from updated moments
		
		tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2); // Compute tau for updated moments
		if (mask[k]!=0){tau[k]=0.5;}
		
		

}
}

for(k=k1;k<k2;k++)//Initialise free energy 
	{
		if(mask[k]!=28)
		{
			if (mask[k]==0)
            {
            d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+C[d[k][10]]+C[d[k][11]]+C[d[k][12]]+C[d[k][13]]+C[d[k][14]]+C[d[k][15]]+C[d[k][16]]+C[d[k][17]]+2.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]]+C[d[k][4]]+C[d[k][5]])-24.0*C[k])/(6.0*dt*dt);

            //d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+4.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/(6.0*dt*dt);
			}
			
		
	/*		
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
	*/		
			
			
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
    		
    		gradmuC5=0.5*(mu[d[k][4]]-mu[d[k][5]])/dt;
    		gradmuC6=0.5*(mu[d[k][5]]-mu[d[k][4]])/dt;
    		gradmuC11=0.5*(mu[d[k][10]]-mu[d[k][13]])/dt;
    		gradmuC12=0.5*(mu[d[k][11]]-mu[d[k][12]])/dt;
    		gradmuC13=0.5*(mu[d[k][12]]-mu[d[k][11]])/dt;
    		gradmuC14=0.5*(mu[d[k][13]]-mu[d[k][10]])/dt;
    		gradmuC15=0.5*(mu[d[k][14]]-mu[d[k][17]])/dt;
    		gradmuC16=0.5*(mu[d[k][15]]-mu[d[k][16]])/dt;
   			 gradmuC17=0.5*(mu[d[k][16]]-mu[d[k][15]])/dt;
    		gradmuC18=0.5*(mu[d[k][17]]-mu[d[k][14]])/dt;
			
			/*
    		gradmuCx=1.0/3.0*(gradmuC1-gradmuC2)+1.0/12.0*(gradmuC7-gradmuC8+gradmuC9-gradmuC10);
    		gradmuCy=1.0/3.0*(gradmuC3-gradmuC4)+1.0/12.0*(gradmuC7+gradmuC8-gradmuC9-gradmuC10);
    		*/
    		
    		gradmuCx=1.0/6.0*(gradmuC1-gradmuC2)+1.0/12.0*(gradmuC7-gradmuC8+gradmuC9-gradmuC10+gradmuC15+gradmuC17-gradmuC16-gradmuC18);
    		gradmuCy=1.0/6.0*(gradmuC3-gradmuC4)+1.0/12.0*(gradmuC7+gradmuC8-gradmuC9-gradmuC10+gradmuC11+gradmuC13-gradmuC12-gradmuC14);
    		gradmuCz=1.0/6.0*(gradmuC5-gradmuC6)+1.0/12.0*(gradmuC11+gradmuC12-gradmuC13-gradmuC14+gradmuC16+gradmuC15-gradmuC17-gradmuC18);
    		
			
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
		     // u[k][2]=0.0;
			 
			 u[k][0]=(3.0*(g[k][1]-g[k][2]+g[k][7]-g[k][10]+g[k][9]-g[k][8]+g[k][15]+g[k][17]-g[k][18]-g[k][16])+0.5*dt*mu[k]*gradCCx)/rho[k];
			 u[k][1]=(3.0*(g[k][3]-g[k][4]+g[k][7]-g[k][10]+g[k][8]-g[k][9]+g[k][11]+g[k][13]-g[k][12]-g[k][14])+0.5*dt*mu[k]*gradCCy)/rho[k];
			 u[k][2]=(3.0*(g[k][5]-g[k][6]+g[k][11]-g[k][14]+g[k][12]-g[k][13]+g[k][15]+g[k][16]-g[k][17]-g[k][18])+0.5*dt*mu[k]*gradCCz)/rho[k];

			
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
    		
    		gradrhoC5=0.5*(rho[d[k][4]]-rho[d[k][5]])/dt;
    gradrhoC6=0.5*(rho[d[k][5]]-rho[d[k][4]])/dt;
    gradrhoC11=0.5*(rho[d[k][10]]-rho[d[k][13]])/dt;
    gradrhoC12=0.5*(rho[d[k][11]]-rho[d[k][12]])/dt;
    gradrhoC13=0.5*(rho[d[k][12]]-rho[d[k][11]])/dt;
    gradrhoC14=0.5*(rho[d[k][13]]-rho[d[k][10]])/dt;
    gradrhoC15=0.5*(rho[d[k][14]]-rho[d[k][17]])/dt;
    gradrhoC16=0.5*(rho[d[k][15]]-rho[d[k][16]])/dt;
    gradrhoC17=0.5*(rho[d[k][16]]-rho[d[k][15]])/dt;
    gradrhoC18=0.5*(rho[d[k][17]]-rho[d[k][14]])/dt;
    		
    		gradrhoCx=1.0/6.0*(gradrhoC1-gradrhoC2)+1.0/12.0*(gradrhoC7-gradrhoC8+gradrhoC9-gradrhoC10+gradrhoC15+gradrhoC17-gradrhoC16-gradrhoC18);
    		gradrhoCy=1.0/6.0*(gradrhoC3-gradrhoC4)+1.0/12.0*(gradrhoC7+gradrhoC8-gradrhoC9-gradrhoC10+gradrhoC11+gradrhoC13-gradrhoC12-gradrhoC14);
    		gradrhoCz=1.0/6.0*(gradrhoC5-gradrhoC6)+1.0/12.0*(gradrhoC11+gradrhoC12-gradrhoC13-gradrhoC14+gradrhoC16+gradrhoC15-gradrhoC17-gradrhoC18);
    		
    		/*
            gradrhoCx=1.0/3.0*(gradrhoC1-gradrhoC2)+1.0/12.0*(gradrhoC7-gradrhoC8+gradrhoC9-gradrhoC10);
    		gradrhoCy=1.0/3.0*(gradrhoC3-gradrhoC4)+1.0/12.0*(gradrhoC7+gradrhoC8-gradrhoC9-gradrhoC10);
			*/
			
			
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
    
	p[k]=g[k][0]+g[k][1]+g[k][2]+g[k][3]+g[k][4]+g[k][7]+g[k][8]+g[k][9]+g[k][10]+g[k][11]+g[k][12]+g[k][13]+g[k][14]+g[k][15]+g[k][16]+g[k][17]+g[k][18]+g[k][5]+g[k][6]+dt*u[k][0]*gradrhoCx/6.0+dt*gradrhoCy*u[k][1]/6.0+dt*gradrhoCz*u[k][2]/6.0;//compute pressure
}
}





}



