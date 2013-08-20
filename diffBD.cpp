//Computes biased differences

#include "wet.h"

void wet::diffBD()
{
	if(dimensions==2)
	{
	gradrhoU1=0.5*(-rho[d[d[k][0]][0]]+4*rho[d[k][0]]-3*rho[k])/dt;
    gradrhoU2=0.5*(-rho[d[d[k][1]][1]]+4*rho[d[k][1]]-3*rho[k])/dt;
    gradrhoU3=0.5*(-rho[d[d[k][2]][2]]+4*rho[d[k][2]]-3*rho[k])/dt;
    gradrhoU4=0.5*(-rho[d[d[k][3]][3]]+4*rho[d[k][3]]-3*rho[k])/dt;
    gradrhoU7=0.5*(-rho[d[d[k][6]][6]]+4*rho[d[k][6]]-3*rho[k])/dt;
    gradrhoU8=0.5*(-rho[d[d[k][7]][7]]+4*rho[d[k][7]]-3*rho[k])/dt;
    gradrhoU9=0.5*(-rho[d[d[k][8]][8]]+4*rho[d[k][8]]-3*rho[k])/dt;
    gradrhoU10=0.5*(-rho[d[d[k][9]][9]]+4*rho[d[k][9]]-3*rho[k])/dt;
	
	gradmuU1=0.5*(-mu[d[d[k][0]][0]]+4*mu[d[k][0]]-3*mu[k])/dt;
    gradmuU2=0.5*(-mu[d[d[k][1]][1]]+4*mu[d[k][1]]-3*mu[k])/dt;
    gradmuU3=0.5*(-mu[d[d[k][2]][2]]+4*mu[d[k][2]]-3*mu[k])/dt;
    gradmuU4=0.5*(-mu[d[d[k][3]][3]]+4*mu[d[k][3]]-3*mu[k])/dt;
    gradmuU7=0.5*(-mu[d[d[k][6]][6]]+4*mu[d[k][6]]-3*mu[k])/dt;
    gradmuU8=0.5*(-mu[d[d[k][7]][7]]+4*mu[d[k][7]]-3*mu[k])/dt;
    gradmuU9=0.5*(-mu[d[d[k][8]][8]]+4*mu[d[k][8]]-3*mu[k])/dt;
    gradmuU10=0.5*(-mu[d[d[k][9]][9]]+4*mu[d[k][9]]-3*mu[k])/dt;

	gradCU1=0.5*(-C[d[d[k][0]][0]]+4*C[d[k][0]]-3*C[k])/dt;
    gradCU2=0.5*(-C[d[d[k][1]][1]]+4*C[d[k][1]]-3*C[k])/dt;
    gradCU3=0.5*(-C[d[d[k][2]][2]]+4*C[d[k][2]]-3*C[k])/dt;
    gradCU4=0.5*(-C[d[d[k][3]][3]]+4*C[d[k][3]]-3*C[k])/dt;
    gradCU7=0.5*(-C[d[d[k][6]][6]]+4*C[d[k][6]]-3*C[k])/dt;
    gradCU8=0.5*(-C[d[d[k][7]][7]]+4*C[d[k][7]]-3*C[k])/dt;
    gradCU9=0.5*(-C[d[d[k][8]][8]]+4*C[d[k][8]]-3*C[k])/dt;
    
    
    gradCU10=0.5*(-C[d[d[k][9]][9]]+4*C[d[k][9]]-3*C[k])/dt;
    
    gradpU1=0.5*(-p[d[d[k][0]][0]]+4*p[d[k][0]]-3*p[k])/dt;
    gradpU2=0.5*(-p[d[d[k][1]][1]]+4*p[d[k][1]]-3*p[k])/dt;
    gradpU3=0.5*(-p[d[d[k][2]][2]]+4*p[d[k][2]]-3*p[k])/dt;
    gradpU4=0.5*(-p[d[d[k][3]][3]]+4*p[d[k][3]]-3*p[k])/dt;
    gradpU7=0.5*(-p[d[d[k][6]][6]]+4*p[d[k][6]]-3*p[k])/dt;
    gradpU8=0.5*(-p[d[d[k][7]][7]]+4*p[d[k][7]]-3*p[k])/dt;
    gradpU9=0.5*(-p[d[d[k][8]][8]]+4*p[d[k][8]]-3*p[k])/dt;
    gradpU10=0.5*(-p[d[d[k][9]][9]]+4*p[d[k][9]]-3*p[k])/dt;
    
    /*
    if(mask[k]==1)
			{
				gradrhoU1=0.5*(-rho[d[d[k][1]][1]]+4*rho[d[k][1]]-3*rho[k]);
				gradrhoU7=0.5*(-rho[d[d[k][7]][7]]+4*rho[d[k][7]]-3*rho[k]);
				gradrhoU9=0.5*(-rho[d[d[k][9]][9]]+4*rho[d[k][9]]-3*rho[k]);
				
				/*
				gradCUx=-dC;
    			gradCUy=1.0/3.0*(gradCU3-gradCU4)+1.0/12.0*(gradCU8+gradCU8-gradCU10-gradCU10);
				
				gradCU1=gradCUx;
				gradCU2=-gradCUx;
				gradCU7=gradCUx+gradCUy;
				gradCU8=-gradCUx+gradCUy;
				gradCU9=gradCUx-gradCUy;
				gradCU10=-gradCUx-gradCUy;
				
				
				
				gradCU1=0.5*(-C[d[d[k][1]][1]]+4*C[d[k][1]]-3*C[k]-4*dC);
				gradCU7=0.5*(-C[d[d[k][7]][7]]+4*C[d[k][7]]-3*C[k]-4*dC);
				gradCU9=0.5*(-C[d[d[k][9]][9]]+4*C[d[k][9]]-3*C[k]-4*dC);
				
				gradmuU1=0.5*(-mu[d[d[k][1]][1]]+4*mu[d[k][1]]-3*mu[k]);
				gradmuU7=0.5*(-mu[d[d[k][7]][7]]+4*mu[d[k][7]]-3*mu[k]);
				gradmuU9=0.5*(-mu[d[d[k][9]][9]]+4*mu[d[k][9]]-3*mu[k]);
				
				gradpU1=0.5*(-p[d[d[k][1]][1]]+4*p[d[k][1]]-3*p[k]);
				gradpU7=0.5*(-p[d[d[k][7]][7]]+4*p[d[k][7]]-3*p[k]);
				gradpU9=0.5*(-p[d[d[k][9]][9]]+4*p[d[k][9]]-3*p[k]);
				
				
			}
			
		if(mask[k]==2)
			{
				gradrhoU2=0.5*(-rho[d[d[k][0]][0]]+4*rho[d[k][0]]-3*rho[k]);
				gradrhoU8=0.5*(-rho[d[d[k][6]][6]]+4*rho[d[k][6]]-3*rho[k]);
				gradrhoU10=0.5*(-rho[d[d[k][8]][8]]+4*rho[d[k][8]]-3*rho[k]);
				
				
				/*
				gradCUx=dC;
    			gradCUy=1.0/3.0*(gradCU3-gradCU4)+1.0/12.0*(gradCU7+gradCU7-gradCU9-gradCU9);
				
				gradCU1=gradCUx;
				gradCU2=-gradCUx;
				gradCU7=gradCUx+gradCUy;
				gradCU8=-gradCUx+gradCUy;
				gradCU9=gradCUx-gradCUy;
				gradCU10=-gradCUx-gradCUy;
				
				
				
				gradCU2=0.5*(-C[d[d[k][0]][0]]+4*C[d[k][0]]-3*C[k]-4*dC);
				gradCU8=0.5*(-C[d[d[k][6]][6]]+4*C[d[k][6]]-3*C[k]-4*dC);
				gradCU10=0.5*(-C[d[d[k][8]][8]]+4*C[d[k][8]]-3*C[k]-4*dC);
				
				gradmuU2=0.5*(-mu[d[d[k][0]][0]]+4*mu[d[k][0]]-3*mu[k]);
				gradmuU8=0.5*(-mu[d[d[k][6]][6]]+4*mu[d[k][6]]-3*mu[k]);
				gradmuU10=0.5*(-mu[d[d[k][8]][8]]+4*mu[d[k][8]]-3*mu[k]);
				
				gradpU2=0.5*(-p[d[d[k][0]][0]]+4*p[d[k][0]]-3*p[k]);
				gradpU8=0.5*(-p[d[d[k][6]][6]]+4*p[d[k][6]]-3*p[k]);
				gradpU10=0.5*(-p[d[d[k][8]][8]]+4*p[d[k][8]]-3*p[k]);
				
				
				
				
			}
    
    if(mask[k]==-1)
    {
    			gradrhoU1=0.5*(-rho[d[d[k][1]][1]]+4*rho[d[k][0]]-3*rho[k]);
				gradrhoU7=0.5*(-rho[d[d[k][7]][7]]+4*rho[d[k][6]]-3*rho[k]);
				gradrhoU9=0.5*(-rho[d[d[k][9]][9]]+4*rho[d[k][8]]-3*rho[k]);
				
				gradCU1=0.5*(-C[d[d[k][1]][1]]+4*C[d[k][0]]-3*C[k]);
				gradCU7=0.5*(-C[d[d[k][7]][7]]+4*C[d[k][6]]-3*C[k]);
				gradCU9=0.5*(-C[d[d[k][9]][9]]+4*C[d[k][8]]-3*C[k]);
				
				gradmuU1=0.5*(-mu[d[d[k][1]][1]]+4*mu[d[k][0]]-3*mu[k]);
				gradmuU7=0.5*(-mu[d[d[k][7]][7]]+4*mu[d[k][6]]-3*mu[k]);
				gradmuU9=0.5*(-mu[d[d[k][9]][9]]+4*mu[d[k][8]]-3*mu[k]);
				
				gradpU1=0.5*(-p[d[d[k][1]][1]]+4*p[d[k][0]]-3*p[k]);
				gradpU7=0.5*(-p[d[d[k][7]][7]]+4*p[d[k][6]]-3*p[k]);
				gradpU9=0.5*(-p[d[d[k][9]][9]]+4*p[d[k][8]]-3*p[k]);
				
				
				
    }
    
    if(mask[k]==-2)
			{
				gradrhoU2=0.5*(-rho[d[d[k][0]][0]]+4*rho[d[k][1]]-3*rho[k]);
				gradrhoU8=0.5*(-rho[d[d[k][6]][6]]+4*rho[d[k][7]]-3*rho[k]);
				gradrhoU10=0.5*(-rho[d[d[k][8]][8]]+4*rho[d[k][9]]-3*rho[k]);
				
				gradCU2=0.5*(-C[d[d[k][0]][0]]+4*C[d[k][1]]-3*C[k]);
				gradCU8=0.5*(-C[d[d[k][6]][6]]+4*C[d[k][7]]-3*C[k]);
				gradCU10=0.5*(-C[d[d[k][8]][8]]+4*C[d[k][9]]-3*C[k]);
				
				gradmuU2=0.5*(-mu[d[d[k][0]][0]]+4*mu[d[k][1]]-3*mu[k]);
				gradmuU8=0.5*(-mu[d[d[k][6]][6]]+4*mu[d[k][7]]-3*mu[k]);
				gradmuU10=0.5*(-mu[d[d[k][8]][8]]+4*mu[d[k][9]]-3*mu[k]);
				
				gradpU2=0.5*(-p[d[d[k][0]][0]]+4*p[d[k][1]]-3*p[k]);
				gradpU8=0.5*(-p[d[d[k][6]][6]]+4*p[d[k][7]]-3*p[k]);
				gradpU10=0.5*(-p[d[d[k][8]][8]]+4*p[d[k][9]]-3*p[k]);
				
				
				
				
				
				
			}
    */
    
    // Work out x and y derivatives
    		
    		gradrhoUx=1.0/3.0*(gradrhoU1-gradrhoU2)+1.0/12.0*(gradrhoU7-gradrhoU8+gradrhoU9-gradrhoU10);
    		gradrhoUy=1.0/3.0*(gradrhoU3-gradrhoU4)+1.0/12.0*(gradrhoU7+gradrhoU8-gradrhoU9-gradrhoU10);
    		
    		
    		gradCUx=1.0/3.0*(gradCU1-gradCU2)+1.0/12.0*(gradCU7-gradCU8+gradCU9-gradCU10);
    		gradCUy=1.0/3.0*(gradCU3-gradCU4)+1.0/12.0*(gradCU7+gradCU8-gradCU9-gradCU10);
    		
    		gradmuUx=1.0/3.0*(gradmuU1-gradmuU2)+1.0/12.0*(gradmuU7-gradmuU8+gradmuU9-gradmuU10);
    		gradmuUy=1.0/3.0*(gradmuU3-gradmuU4)+1.0/12.0*(gradmuU7+gradmuU8-gradmuU9-gradmuU10);
    		
    		gradpUx=1.0/3.0*(gradpU1-gradpU2)+1.0/12.0*(gradpU7-gradpU8+gradpU9-gradpU10);
    		gradpUy=1.0/3.0*(gradpU3-gradpU4)+1.0/12.0*(gradpU7+gradpU8-gradpU9-gradpU10);
    
    
	}
}