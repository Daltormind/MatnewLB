//Computes differentials using second order central difference scheme

#include "wet.h"

void wet::diffCD()
{
		//dC=Wc*(C[k]-C[k]*C[k]);
		
		if (dimensions==2)
		{
			// First calculate Directional derivatives 
			if(mask[k]==0)
			{
			gradrhoC1=0.5*(rho[d[k][0]]-rho[d[k][1]])/dt;
			gradrhoC2=0.5*(rho[d[k][1]]-rho[d[k][0]])/dt;
    		gradrhoC3=0.5*(rho[d[k][2]]-rho[d[k][3]])/dt;
    		gradrhoC4=0.5*(rho[d[k][3]]-rho[d[k][2]])/dt;
    		gradrhoC7=0.5*(rho[d[k][6]]-rho[d[k][9]])/dt;
    		gradrhoC8=0.5*(rho[d[k][7]]-rho[d[k][8]])/dt;
    		gradrhoC9=0.5*(rho[d[k][8]]-rho[d[k][7]])/dt;
    		gradrhoC10=0.5*(rho[d[k][9]]-rho[d[k][6]])/dt;

    		gradCC1=0.5*(C[d[k][0]]-C[d[k][1]])/dt;
			gradCC2=0.5*(C[d[k][1]]-C[d[k][0]])/dt;
    		gradCC3=0.5*(C[d[k][2]]-C[d[k][3]])/dt;
    		gradCC4=0.5*(C[d[k][3]]-C[d[k][2]])/dt;
    		gradCC7=0.5*(C[d[k][6]]-C[d[k][9]])/dt;
    		gradCC8=0.5*(C[d[k][7]]-C[d[k][8]])/dt;
    		gradCC9=0.5*(C[d[k][8]]-C[d[k][7]])/dt;
    		gradCC10=0.5*(C[d[k][9]]-C[d[k][6]])/dt;
    		
    		gradmuC1=0.5*(mu[d[k][0]]-mu[d[k][1]])/dt;
			gradmuC2=0.5*(mu[d[k][1]]-mu[d[k][0]])/dt;
    		gradmuC3=0.5*(mu[d[k][2]]-mu[d[k][3]])/dt;
    		gradmuC4=0.5*(mu[d[k][3]]-mu[d[k][2]])/dt;
    		gradmuC7=0.5*(mu[d[k][6]]-mu[d[k][9]])/dt;
    		gradmuC8=0.5*(mu[d[k][7]]-mu[d[k][8]])/dt;
    		gradmuC9=0.5*(mu[d[k][8]]-mu[d[k][7]])/dt;
    		gradmuC10=0.5*(mu[d[k][9]]-mu[d[k][6]])/dt;
    		
    		gradpC1=0.5*(p[d[k][0]]-p[d[k][1]])/dt;
			gradpC2=0.5*(p[d[k][1]]-p[d[k][0]])/dt;
    		gradpC3=0.5*(p[d[k][2]]-p[d[k][3]])/dt;
    		gradpC4=0.5*(p[d[k][3]]-p[d[k][2]])/dt;
    		gradpC7=0.5*(p[d[k][6]]-p[d[k][9]])/dt;
    		gradpC8=0.5*(p[d[k][7]]-p[d[k][8]])/dt;
    		gradpC9=0.5*(p[d[k][8]]-p[d[k][7]])/dt;
    		gradpC10=0.5*(p[d[k][9]]-p[d[k][6]])/dt;
    		}
    		
    			else if(mask[k]==1 or mask[k]==2)
			{
				gradrhoC1=0.0;
				gradrhoC2=0.0;
				gradrhoC7=0.0;
				gradrhoC8=0.0;
				gradrhoC9=0.0;
				gradrhoC10=0.0;
				gradrhoC3=0.5*(rho[d[k][2]]-rho[d[k][3]])/dt;
    			gradrhoC4=0.5*(rho[d[k][3]]-rho[d[k][2]])/dt;
    			
    			gradCC1=0.0;
				gradCC2=0.0;
				gradCC7=0.0;
				gradCC8=0.0;
				gradCC9=0.0;
				gradCC10=0.0;
				gradCC3=0.5*(C[d[k][2]]-C[d[k][3]])/dt;
    			gradCC4=0.5*(C[d[k][3]]-C[d[k][2]])/dt;
    			
    			gradmuC1=0.0;
				gradmuC2=0.0;
				gradmuC7=0.0;
				gradmuC8=0.0;
				gradmuC9=0.0;
				gradmuC10=0.0;
				gradmuC3=0.5*(mu[d[k][2]]-mu[d[k][3]])/dt;
    			gradmuC4=0.5*(mu[d[k][3]]-mu[d[k][2]])/dt;
    			
    			gradpC1=0.0;
				gradpC2=0.0;
				gradpC7=0.0;
				gradpC8=0.0;
				gradpC9=0.0;
				gradpC10=0.0;
				gradpC3=0.5*(p[d[k][2]]-p[d[k][3]])/dt;
    			gradpC4=0.5*(p[d[k][3]]-p[d[k][2]])/dt;
				
				
				
				
				
			}
			
			else if(mask[k]==3 or mask[k]==4)
			{
				
				
				gradrhoC3=0.0;
				gradrhoC4=0.0;
				gradrhoC7=0.0;
				gradrhoC8=0.0;
				gradrhoC9=0.0;
				gradrhoC10=0.0;
				gradrhoC1=0.5*(rho[d[k][0]]-rho[d[k][1]])/dt;
				gradrhoC2=0.5*(rho[d[k][1]]-rho[d[k][0]])/dt;
				
				gradCC3=0.0;
				gradCC4=0.0;
				gradCC7=0.0;
				gradCC8=0.0;
				gradCC9=0.0;
				gradCC10=0.0;
				gradCC1=0.5*(C[d[k][0]]-C[d[k][1]])/dt;
				gradCC2=0.5*(C[d[k][1]]-C[d[k][0]])/dt;
				
				gradmuC3=0.0;
				gradmuC4=0.0;
				gradmuC7=0.0;
				gradmuC8=0.0;
				gradmuC9=0.0;
				gradmuC10=0.0;
				gradmuC1=0.5*(mu[d[k][0]]-mu[d[k][1]])/dt;
				gradmuC2=0.5*(mu[d[k][1]]-mu[d[k][0]])/dt;
				
				gradpC3=0.0;
				gradpC4=0.0;
				gradpC7=0.0;
				gradpC8=0.0;
				gradpC9=0.0;
				gradpC10=0.0;
				gradpC1=0.5*(p[d[k][0]]-p[d[k][1]])/dt;
				gradpC2=0.5*(p[d[k][1]]-p[d[k][0]])/dt;
				
				
				
				
				
			}
			
			else if(mask[k]==7 or mask[k]==10)
			{
			gradrhoC1=0.5*(rho[d[k][0]]-rho[d[k][1]])/dt;
			gradrhoC2=0.5*(rho[d[k][1]]-rho[d[k][0]])/dt;
    		gradrhoC3=0.5*(rho[d[k][2]]-rho[d[k][3]])/dt;
    		gradrhoC4=0.5*(rho[d[k][3]]-rho[d[k][2]])/dt;
    		gradrhoC7=0.0;
    		gradrhoC8=0.5*(rho[d[k][7]]-rho[d[k][8]])/dt;
    		gradrhoC9=0.5*(rho[d[k][8]]-rho[d[k][7]])/dt;
    		gradrhoC10=0.0;

    		gradCC1=0.5*(C[d[k][0]]-C[d[k][1]])/dt;
			gradCC2=0.5*(C[d[k][1]]-C[d[k][0]])/dt;
    		gradCC3=0.5*(C[d[k][2]]-C[d[k][3]])/dt;
    		gradCC4=0.5*(C[d[k][3]]-C[d[k][2]])/dt;
    		gradCC7=0.0;
    		gradCC8=0.5*(C[d[k][7]]-C[d[k][8]])/dt;
    		gradCC9=0.5*(C[d[k][8]]-C[d[k][7]])/dt;
    		gradCC10=0.0;
    		
    		gradmuC1=0.5*(mu[d[k][0]]-mu[d[k][1]])/dt;
			gradmuC2=0.5*(mu[d[k][1]]-mu[d[k][0]])/dt;
    		gradmuC3=0.5*(mu[d[k][2]]-mu[d[k][3]])/dt;
    		gradmuC4=0.5*(mu[d[k][3]]-mu[d[k][2]])/dt;
    		gradmuC7=0.0;
    		gradmuC8=0.5*(mu[d[k][7]]-mu[d[k][8]])/dt;
    		gradmuC9=0.5*(mu[d[k][8]]-mu[d[k][7]])/dt;
    		gradmuC10=0.0;
    		
    		gradpC1=0.5*(p[d[k][0]]-p[d[k][1]])/dt;
			gradpC2=0.5*(p[d[k][1]]-p[d[k][0]])/dt;
    		gradpC3=0.5*(p[d[k][2]]-p[d[k][3]])/dt;
    		gradpC4=0.5*(p[d[k][3]]-p[d[k][2]])/dt;
    		gradpC7=0.0;
    		gradpC8=0.5*(p[d[k][7]]-p[d[k][8]])/dt;
    		gradpC9=0.5*(p[d[k][8]]-p[d[k][7]])/dt;
    		gradpC10=0.0;
    		}
    		
    		else if(mask[k]==8 or mask[k]==9)
			{
			gradrhoC1=0.5*(rho[d[k][0]]-rho[d[k][1]])/dt;
			gradrhoC2=0.5*(rho[d[k][1]]-rho[d[k][0]])/dt;
    		gradrhoC3=0.5*(rho[d[k][2]]-rho[d[k][3]])/dt;
    		gradrhoC4=0.5*(rho[d[k][3]]-rho[d[k][2]])/dt;
    		gradrhoC7=0.5*(rho[d[k][6]]-rho[d[k][9]])/dt;
    		gradrhoC8=0.0;
    		gradrhoC9=0.0;
    		gradrhoC10=0.5*(rho[d[k][9]]-rho[d[k][6]])/dt;

    		gradCC1=0.5*(C[d[k][0]]-C[d[k][1]])/dt;
			gradCC2=0.5*(C[d[k][1]]-C[d[k][0]])/dt;
    		gradCC3=0.5*(C[d[k][2]]-C[d[k][3]])/dt;
    		gradCC4=0.5*(C[d[k][3]]-C[d[k][2]])/dt;
    		gradCC7=0.5*(C[d[k][6]]-C[d[k][9]])/dt;
    		gradCC8=0.0;
    		gradCC9=0.0;
    		gradCC10=0.5*(C[d[k][9]]-C[d[k][6]])/dt;
    		
    		gradmuC1=0.5*(mu[d[k][0]]-mu[d[k][1]])/dt;
			gradmuC2=0.5*(mu[d[k][1]]-mu[d[k][0]])/dt;
    		gradmuC3=0.5*(mu[d[k][2]]-mu[d[k][3]])/dt;
    		gradmuC4=0.5*(mu[d[k][3]]-mu[d[k][2]])/dt;
    		gradmuC7=0.5*(mu[d[k][6]]-mu[d[k][9]])/dt;
    		gradmuC8=0.0;
    		gradmuC9=0.0;
    		gradmuC10=0.5*(mu[d[k][9]]-mu[d[k][6]])/dt;
    		
    		gradpC1=0.5*(p[d[k][0]]-p[d[k][1]])/dt;
			gradpC2=0.5*(p[d[k][1]]-p[d[k][0]])/dt;
    		gradpC3=0.5*(p[d[k][2]]-p[d[k][3]])/dt;
    		gradpC4=0.5*(p[d[k][3]]-p[d[k][2]])/dt;
    		gradpC7=0.5*(p[d[k][6]]-p[d[k][9]])/dt;
    		gradpC8=0.0;
    		gradpC9=0.0;
    		gradpC10=0.5*(p[d[k][9]]-p[d[k][6]])/dt;
    		}
    		
    		else if(mask[k]==31 or mask[k]==31 or mask[k]==41 or mask[k]==42)
			{
			gradrhoC1=0.0;
			gradrhoC2=0.0;
    		gradrhoC3=0.0;
    		gradrhoC4=0.0;
    		gradrhoC7=0.0;
    		gradrhoC8=0.0;
    		gradrhoC9=0.0;
    		gradrhoC10=0.0;

    		gradCC1=0.0;
			gradCC2=0.0;
    		gradCC3=0.0;
    		gradCC4=0.0;
    		gradCC7=0.0;
    		gradCC8=0.0;
    		gradCC9=0.0;
    		gradCC10=0.0;
    		
    		gradmuC1=0.0;
			gradmuC2=0.0;
    		gradmuC3=0.0;
    		gradmuC4=0.0;
    		gradmuC7=0.0;
    		gradmuC8=0.0;
    		gradmuC9=0.0;
    		gradmuC10=0.0;
    		
    		gradpC1=0.0;
			gradpC2=0.0;
    		gradpC3=0.0;
    		gradpC4=0.0;
    		gradpC7=0.0;
    		gradpC8=0.0;
    		gradpC9=0.0;
    		gradpC10=0.0;
    		}
    		
    		
    		// Work out x and y derivatives
    		
    		gradrhoCx=1.0/3.0*(gradrhoC1-gradrhoC2)+1.0/12.0*(gradrhoC7-gradrhoC8+gradrhoC9-gradrhoC10);
    		gradrhoCy=1.0/3.0*(gradrhoC3-gradrhoC4)+1.0/12.0*(gradrhoC7+gradrhoC8-gradrhoC9-gradrhoC10);
    		
    		
    		gradCCx=1.0/3.0*(gradCC1-gradCC2)+1.0/12.0*(gradCC7-gradCC8+gradCC9-gradCC10);
    		gradCCy=1.0/3.0*(gradCC3-gradCC4)+1.0/12.0*(gradCC7+gradCC8-gradCC9-gradCC10);
    		
    		gradmuCx=1.0/3.0*(gradmuC1-gradmuC2)+1.0/12.0*(gradmuC7-gradmuC8+gradmuC9-gradmuC10);
    		gradmuCy=1.0/3.0*(gradmuC3-gradmuC4)+1.0/12.0*(gradmuC7+gradmuC8-gradmuC9-gradmuC10);
    		
    		gradpCx=1.0/3.0*(gradpC1-gradpC2)+1.0/12.0*(gradpC7-gradpC8+gradpC9-gradpC10);
    		gradpCy=1.0/3.0*(gradpC3-gradpC4)+1.0/12.0*(gradpC7+gradpC8-gradpC9-gradpC10);
		
			
		
		
		
		}
		
		


}