//Computes differentials using second order central difference scheme

#include "wet.h"

void wet::diffCD()
{
	
		
		if (dimensions==2)
		{
			// First calculate Directional derivatives 
			
			gradrhoC1=0.5*(rho[d[k][0]]-rho[d[k][1]]);
			gradrhoC2=0.5*(rho[d[k][1]]-rho[d[k][0]]);
    		gradrhoC3=0.5*(rho[d[k][2]]-rho[d[k][3]);
    		gradrhoC4=0.5*(rho[d[k][3]]-rho[d[k][2]]);
    		gradrhoC7=0.5*(rho[d[k][6]]-rho[d[k][9]]);
    		gradrhoC8=0.5*(rho[d[k][7]]-rho[d[k][8]]);
    		gradrhoC9=0.5*(rho[d[k][8]]-rho[d[k][7]]);
    		gradrhoC10=0.5*(rho[d[k][9]]-rho[d[k][6]]);

    		gradCC1=0.5*(C[d[k][0]]-C[d[k][1]]);
			gradCC2=0.5*(C[d[k][1]]-C[d[k][0]]);
    		gradCC3=0.5*(C[d[k][2]]-C[d[k][3]);
    		gradCC4=0.5*(C[d[k][3]]-C[d[k][2]]);
    		gradCC7=0.5*(C[d[k][6]]-C[d[k][9]]);
    		gradCC8=0.5*(C[d[k][7]]-C[d[k][8]]);
    		gradCC9=0.5*(C[d[k][8]]-C[d[k][7]]);
    		gradCC10=0.5*(C[d[k][9]]-C[d[k][6]]);
    		
    		gradmuC1=0.5*(mu[d[k][0]]-mu[d[k][1]]);
			gradmuC2=0.5*(mu[d[k][1]]-mu[d[k][0]]);
    		gradmuC3=0.5*(mu[d[k][2]]-mu[d[k][3]);
    		gradmuC4=0.5*(mu[d[k][3]]-mu[d[k][2]]);
    		gradmuC7=0.5*(mu[d[k][6]]-mu[d[k][9]]);
    		gradmuC8=0.5*(mu[d[k][7]]-mu[d[k][8]]);
    		gradmuC9=0.5*(mu[d[k][8]]-mu[d[k][7]]);
    		gradmuC10=0.5*(mu[d[k][9]]-mu[d[k][6]]);
    		
    		gradpC1=0.5*(p[d[k][0]]-p[d[k][1]]);
			gradpC2=0.5*(p[d[k][1]]-p[d[k][0]]);
    		gradpC3=0.5*(p[d[k][2]]-p[d[k][3]);
    		gradpC4=0.5*(p[d[k][3]]-p[d[k][2]]);
    		gradpC7=0.5*(p[d[k][6]]-p[d[k][9]]);
    		gradpC8=0.5*(p[d[k][7]]-p[d[k][8]]);
    		gradpC9=0.5*(p[d[k][8]]-p[d[k][7]]);
    		gradpC10=0.5*(p[d[k][9]]-p[d[k][6]]);
    		
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