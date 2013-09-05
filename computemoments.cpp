//Computemoments


#include "wet.h"

void wet::computemoments()
{



//Compute Composition C
for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{

		
		

		if(dimensions==3)
		{
		C[k]=h0[k]+h1[k]+h2[k]+h3[k]+h4[k]+h7[k]+h8[k]+h9[k]+h10[k]+h11[k]+h12[k]+h13[k]+h14[k]+h15[k]+h16[k]+h17[k]+h18[k]+h5[k]+h6[k]; //Compute C from updated velocity distributions
		}
		if(dimensions==2)
		{
		C[k]=h0[k]+h1[k]+h2[k]+h3[k]+h4[k]+h7[k]+h8[k]+h9[k]+h10[k]; //Compute C from updated velocity distributions

		}
		//rho[k]=f[k][0]+f[k][1]+f[k][2]+f[k][3]+f[k][4]+f[k][7]+f[k][8]+f[k][9]+f[k][10];
		
		
		
		rho[k]=C[k]*rho1+(1-C[k])*rho2; //Compute Rho from updated moments
		
		tau[k]=1.0/(C[k]/tau1+(1-C[k])/tau2); // Compute tau for updated moments
		if (mask[k]==1){tau[k]=0.5;}
		
		

}
}

exchangeC();
exchangerho();

for(k=k1;k<k2;k++)//Compute free energy 
	{
		if(mask[k]!=28)
		{
			if (mask[k]!=1)
            {
            if(dimensions==3)
            {
            d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+C[d[k][10]]+C[d[k][11]]+C[d[k][12]]+C[d[k][13]]+C[d[k][14]]+C[d[k][15]]+C[d[k][16]]+C[d[k][17]]+2.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]]+C[d[k][4]]+C[d[k][5]])-24.0*C[k])/(6.0*dt*dt);
			}
			if(dimensions==2)
			{
            d2C=(C[d[k][6]]+C[d[k][7]]+C[d[k][8]]+C[d[k][9]]+4.0*(C[d[k][0]]+C[d[k][1]]+C[d[k][2]]+C[d[k][3]])-20.0*C[k])/(6.0*dt*dt);
			}
			}
			else if (mask[k]==1)
			{
			
				dC=Wc*(C[k]-C[k]*C[k]);
				if(mask[d[k][0]]==28)
    	{hold1=C[d[k][1]]-2*dC;}else{hold1=C[d[k][0]];}
    	
    	if(mask[d[k][1]]==28)
    	{hold2=C[d[k][0]]-2*dC;}else{hold2=C[d[k][1]];}
    	
    	if(mask[d[k][2]]==28)
    	{hold3=C[d[k][2]]-2*dC;}else{hold3=C[d[k][2]];}
    	
    	if(mask[d[k][3]]==28)
    	{hold4=C[d[k][3]]-2*dC;}else{hold4=C[d[k][3]];}
    	
    	if(mask[d[k][4]]==28)
    	{hold5=C[d[k][4]]-2*dC;}else{hold5=C[d[k][4]];}
    	
    	if(mask[d[k][5]]==28)
    	{hold6=C[d[k][5]]-2*dC;}else{hold6=C[d[k][5]];}
    	
    	if(mask[d[k][6]]==28)
    	{hold7=C[d[k][9]]-2*dC;}else{hold7=C[d[k][6]];}
    	
    	if(mask[d[k][7]]==28 || mask[d[d[k][7]][7]]==2)
    	{hold8=C[d[k][8]]-2*dC;}else{hold8=C[d[k][7]];}
    	
    	if(mask[d[k][8]]==28 || mask[d[d[k][8]][8]]==2)
    	{hold9=C[d[k][7]]-2*dC;}else{hold9=C[d[k][8]];}
    	
    	if(mask[d[k][9]]==28 || mask[d[d[k][9]][9]]==2)
    	{hold10=C[d[k][6]]-2*dC;}else{hold10=C[d[k][9]];}
    	
    	if(mask[d[k][10]]==28 || mask[d[d[k][10]][10]]==2)
    	{hold11=C[d[k][13]]-2*dC;}else{hold11=C[d[k][10]];}
    	
    	if(mask[d[k][11]]==28 || mask[d[d[k][11]][11]]==2)
    	{hold12=C[d[k][12]]-2*dC;}else{hold12=C[d[k][11]];}
    	
    	if(mask[d[k][12]]==28 || mask[d[d[k][12]][12]]==2)
    	{hold13=C[d[k][11]]-2*dC;}else{hold13=C[d[k][12]];}
    	
    	if(mask[d[k][13]]==28 || mask[d[d[k][13]][13]]==2)
    	{hold14=C[d[k][10]]-2*dC;}else{hold14=C[d[k][13]];}
    	
    	if(mask[d[k][14]]==28 || mask[d[d[k][14]][14]]==2)
    	{hold15=C[d[k][17]]-2*dC;}else{hold15=C[d[k][14]];}
    	
    	if(mask[d[k][15]]==28 || mask[d[d[k][15]][15]]==2)
    	{hold16=C[d[k][16]]-2*dC;}else{hold16=C[d[k][15]];}
    	
    	if(mask[d[k][16]]==28 || mask[d[d[k][16]][16]]==2)
    	{hold17=C[d[k][15]]-2*dC;}else{hold17=C[d[k][16]];}
    	
    	if(mask[d[k][17]]==28 || mask[d[d[k][17]][17]]==2)
    	{hold18=C[d[k][14]]-2*dC;}else{hold18=C[d[k][17]];}
			
			if(dimensions==3)
            {
            d2C=(hold7+hold8+hold9+hold10+hold11+hold12+hold13+hold14+hold15+hold16+hold17+hold18+2.0*(hold1+hold2+hold3+hold4+hold5+hold6)-24.0*C[k])/(6.0*dt*dt);
			}
			if(dimensions==2)
			{
            d2C=(hold7+hold8+hold9+hold10+4.0*(hold1+hold2+hold3+hold4)-20.0*C[k])/(6.0*dt*dt);
			}
			
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
	
exchangemu();	

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
			
			if(dimensions==2)
			{
    		gradmuCx=1.0/3.0*(gradmuC1-gradmuC2)+1.0/12.0*(gradmuC7-gradmuC8+gradmuC9-gradmuC10);
    		gradmuCy=1.0/3.0*(gradmuC3-gradmuC4)+1.0/12.0*(gradmuC7+gradmuC8-gradmuC9-gradmuC10);
    		}
    		if(dimensions==3)
    		{
    		gradmuCx=1.0/6.0*(gradmuC1-gradmuC2)+1.0/12.0*(gradmuC7-gradmuC8+gradmuC9-gradmuC10+gradmuC15+gradmuC17-gradmuC16-gradmuC18);
    		gradmuCy=1.0/6.0*(gradmuC3-gradmuC4)+1.0/12.0*(gradmuC7+gradmuC8-gradmuC9-gradmuC10+gradmuC11+gradmuC13-gradmuC12-gradmuC14);
    		gradmuCz=1.0/6.0*(gradmuC5-gradmuC6)+1.0/12.0*(gradmuC11+gradmuC12-gradmuC13-gradmuC14+gradmuC16+gradmuC15-gradmuC17-gradmuC18);
    		}
			
			/*
			if(st<50)
			{
            ux[k]=0.0;//(3.0*(g1[k]-g2[k]+g7[k]-g10[k]+g9[k]-g8[k])-0.5*C[k]*gradmuCx)/rho[k];
            uy[k]=0.0;//(3.0*(g3[k]-g4[k]+g7[k]-g10[k]+g8[k]-g9[k])-0.5*C[k]*gradmuCy)/rho[k];
			}
			else
			{
				ux[k]=(3.0*(g1[k]-g2[k]+g7[k]-g10[k]+g9[k]-g8[k])-0.5*C[k]*gradmuCx)/rho[k];
            	uy[k]=(3.0*(g3[k]-g4[k]+g7[k]-g10[k]+g8[k]-g9[k])-0.5*C[k]*gradmuCy)/rho[k];
			}
			*/
			
			
			
			//ux[k]=0.0;
		      //uy[k]=0.0;
		     // uz[k]=0.0;
			 
			 if(dimensions==3)
			 {
			 ux[k]=(3.0*(g1[k]-g2[k]+g7[k]-g10[k]+g9[k]-g8[k]+g15[k]+g17[k]-g18[k]-g16[k])+0.5*dt*mu[k]*gradCCx)/rho[k];
			 uy[k]=(3.0*(g3[k]-g4[k]+g7[k]-g10[k]+g8[k]-g9[k]+g11[k]+g13[k]-g12[k]-g14[k])+0.5*dt*mu[k]*gradCCy)/rho[k];
			 uz[k]=(3.0*(g5[k]-g6[k]+g11[k]-g14[k]+g12[k]-g13[k]+g15[k]+g16[k]-g17[k]-g18[k])+0.5*dt*mu[k]*gradCCz)/rho[k];
			}
			
			if(dimensions==2)
			{
			ux[k]=((g1[k]-g2[k]+g7[k]-g10[k]+g9[k]-g8[k])+0.5*dt*mu[k]*gradCCx)/rho[k];
            uy[k]=((g3[k]-g4[k]+g7[k]-g10[k]+g8[k]-g9[k])+0.5*dt*mu[k]*gradCCy)/rho[k];
			uz[k]=0.0;
			}
}
}

exchangevel();

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
    		
    		if(dimensions==3)
    		{
    		gradrhoCx=1.0/6.0*(gradrhoC1-gradrhoC2)+1.0/12.0*(gradrhoC7-gradrhoC8+gradrhoC9-gradrhoC10+gradrhoC15+gradrhoC17-gradrhoC16-gradrhoC18);
    		gradrhoCy=1.0/6.0*(gradrhoC3-gradrhoC4)+1.0/12.0*(gradrhoC7+gradrhoC8-gradrhoC9-gradrhoC10+gradrhoC11+gradrhoC13-gradrhoC12-gradrhoC14);
    		gradrhoCz=1.0/6.0*(gradrhoC5-gradrhoC6)+1.0/12.0*(gradrhoC11+gradrhoC12-gradrhoC13-gradrhoC14+gradrhoC16+gradrhoC15-gradrhoC17-gradrhoC18);
    		}
    		if (dimensions==2)
    		{
            gradrhoCx=1.0/3.0*(gradrhoC1-gradrhoC2)+1.0/12.0*(gradrhoC7-gradrhoC8+gradrhoC9-gradrhoC10);
    		gradrhoCy=1.0/3.0*(gradrhoC3-gradrhoC4)+1.0/12.0*(gradrhoC7+gradrhoC8-gradrhoC9-gradrhoC10);
			}
			
			
	/*
	if(st<50)
	{
	p[k]=0.0;
    }
    
    else
    {
    p[k]=g0[k]+g1[k]+g2[k]+g3[k]+g4[k]+g7[k]+g8[k]+g9[k]+g10[k]+ux[k]*gradrhoCx/6.0+gradrhoCy*uy[k]/6.0;
	}
    */
    
    //p[k]=0.0;
    if (dimensions==3)
    {
	p[k]=g0[k]+g1[k]+g2[k]+g3[k]+g4[k]+g7[k]+g8[k]+g9[k]+g10[k]+g11[k]+g12[k]+g13[k]+g14[k]+g15[k]+g16[k]+g17[k]+g18[k]+g5[k]+g6[k]+dt*ux[k]*gradrhoCx/6.0+dt*gradrhoCy*uy[k]/6.0+dt*gradrhoCz*uz[k]/6.0;//compute pressure
	}
	if(dimensions==2)
	{
		p[k]=g0[k]+g1[k]+g2[k]+g3[k]+g4[k]+g7[k]+g8[k]+g9[k]+g10[k]+dt*ux[k]*gradrhoCx/6.0+dt*gradrhoCy*uy[k]/6.0;//compute pressure

	}
}
}

exchangep();




}



