//Computes the force terms for g and h

#include "wet.h"

void wet ::centralforce()
{

		//compute gamma
		 gamma0 = 4.0/9.0*rho[i][j]*(1.0-1.5*(u[k][0]*u[k][0]+u[k][1]*u[k][1]));
         gamma1 = 1.0/9.0*rho[i][j]*(1.0+3.0*u[k][0]+3.0*u[k][0]*u[k][0]-1.5*u[k][1]*u[k][1]);
         gamma3 = 1.0/9.0*rho[i][j]*(1.0+3.0*u[k][1]+3.0*u[k][1]*u[k][1]-1.5*u[k][0]*u[k][0]);
         gamma2 = 1.0/9.0*rho[i][j]*(1.0-3.0*u[k][0]+3.0*u[k][0]*u[k][0]-1.5*u[k][1]*u[k][1]);
         gamma4 = 1.0/9.0*rho[i][j]*(1.0-3.0*u[k][1]+3.0*u[k][1]*u[k][1]-1.5*u[k][0]*u[k][0]);
         gamma7 = 1.0/36.0*rho[i][j]*(1.0+3.0*(u[k][0]+u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])+9.0*u[k][0]*u[k][1]);
         gamma8 = 1.0/36.0*rho[i][j]*(1.0+3.0*(-u[k][0]+u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])-9.0*u[k][0]*u[k][1]);
         gamma10 = 1.0/36.0*rho[i][j]*(1.0+3.0*(-u[k][0]-u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])+9.0*u[k][0]*u[k][1]);
         gamma9 = 1.0/36.0*rho[i][j]*(1.0+3.0*(u[k][0]-u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])-9.0*u[k][0]*u[k][1]);

         FhC1=(gradCC1-3.0*C[k]/rho[k]*(gradpC1+C[k]*gradMuC1));
    	 FhC2=(gradCC2-3.0*C[k]/rho[k]*(gradpC2+C[k]*gradMuC2));
    	 FhC3=(gradCC3-3.0*C[k]/rho[k]*(gradpC3+C[k]*gradMuC3));
    	 FhC4=(gradCC4-3.0*C[k]/rho[k]*(gradpC4+C[k]*gradMuC4));
      	 FhC7=(gradCC5-3.0*C[k]/rho[k]*(gradpC7+C[k]*gradMuC7));
     	 FhC8=(gradCC6-3.0*C[k]/rho[k]*(gradpC8+C[k]*gradMuC8));
   		 FhC9=(gradCC9-3.0*C[k]/rho[k]*(gradpC9+C[k]*gradMuC9));
  	     FhC10=(gradCC10-3.0*C[k]/rho[k]*(gradpC10+C[k]*gradMuC10));

  	     FhCx=(gradCCx-3.0*C[k]/rho[k]*(gradpCx+C[k]*gradMuCx));
  	     FhCy=(gradCCy-3.0*C[k]/rho[k]*(gradpCy+C[k]*gradMuCy));


  	     FgC1=gradrhoC1/3.0-C[k]*gradmuC1;
    	 FgC2=gradrhoC2/3.0-C[k]*gradmuC2;
    	 FgC3=gradrhoC3/3.0-C[k]*gradmuC3;
    	 FgC4=gradrhoC4/3.0-C[k]*gradmuC4;
      	 FgC7=gradrhoC7/3.0-C[k]*gradmuC7;
		 FgC8=gradrhoC8/3.0-C[k]*gradmuC8;
		 FgC9=gradrhoC9/3.0-C[k]*gradmuC9;
		 FgC10=gradrhoC10/3.0-C[k]*gradmuC10;

		 FgCx=gradrhoCx/3.0-C[k]*gradmuCx;
		 FgCy=gradrhoCy/3.0-C[k]*gradmuCy;

		 FhU1=(gradCU1-3.0*C[k]/rho[k]*(gradpU1+C[k]*gradMuU1));
    	 FhU2=(gradCU2-3.0*C[k]/rho[k]*(gradpU2+C[k]*gradMuU2));
    	 FhU3=(gradCU3-3.0*C[k]/rho[k]*(gradpU3+C[k]*gradMuU3));
    	 FhU4=(gradCU4-3.0*C[k]/rho[k]*(gradpU4+C[k]*gradMuU4));
      	 FhU7=(gradCU5-3.0*C[k]/rho[k]*(gradpU7+C[k]*gradMuU7));
     	 FhU8=(gradCU6-3.0*C[k]/rho[k]*(gradpU8+C[k]*gradMuU8));
   		 FhU9=(gradCU9-3.0*C[k]/rho[k]*(gradpU9+C[k]*gradMuU9));
  	     FhU10=(gradCU10-3.0*C[k]/rho[k]*(gradpU10+C[k]*gradMuU10));

  	     FhUx=(gradUUx-3.0*U[k]/rho[k]*(gradpUx+U[k]*gradMuUx));
  	     FhUy=(gradUUy-3.0*U[k]/rho[k]*(gradpUy+U[k]*gradMuUy));

  	     FgU1=gradrhoU1/3.0-C[k]*gradmuU1;
    	 FgU2=gradrhoU2/3.0-C[k]*gradmuU2;
    	 FgU3=gradrhoU3/3.0-C[k]*gradmuU3;
    	 FgU4=gradrhoU4/3.0-C[k]*gradmuU4;
      	 FgU7=gradrhoU7/3.0-C[k]*gradmuU7;
		 FgU8=gradrhoU8/3.0-C[k]*gradmuU8;
		 FgU9=gradrhoU9/3.0-C[k]*gradmuU9;
		 FgU10=gradrhoU10/3.0-C[k]*gradmuU10;

		 FgUx=gradrhoUx/3.0-U[k]*gradmuUx;
		 FgUy=gradrhoUy/3.0-U[k]*gradmuUy;

		 FgM1=FgU1+FgC1;
		 FgM2=FgU2+FgC2;
		 FgM3=FgU3+FgC3;
		 FgM4=FgU4+FgC4;
		 FgM7=FgU7+FgC7;
		 FgM8=FgU8+FgC8;
		 FgM9=FgU9+FgC9;
		 FgM10=FgU10+FgC10;
		 FgMx=FgUx+FgCx;
		 FgMy=FgUy+FgCy;



         FhM1=FhU1+FhC1;
		 FhM2=FhU2+FhC2;
		 FhM3=FhU3+FhC3;
		 FhM4=FhU4+FhC4;
		 FhM7=FhU7+FhC7;
		 FhM8=FhU8+FhC8;
		 FhM9=FhU9+FhC9;
		 FhM10=FhU10+FhC10;
         FhMx=FhUx+FhCx;
		 FhMy=FhUy+FhCy;

		 gradrhoM1=gradrhoC1+gradrhoU1;
		 gradrhoM2=gradrhoC2+gradrhoU2;
		 gradrhoM3=gradrhoC3+gradrhoU3;
		 gradrhoM4=gradrhoC4+gradrhoU4;
		 gradrhoM7=gradrhoC7+gradrhoU7;
		 gradrhoM8=gradrhoC8+gradrhoU8;
		 gradrhoM9=gradrhoC9+gradrhoU9;
		 gradrhoM10=gradrhoC10+gradrhoU10;

		 gradrhoMx=gradrhoCx+gradrhoUx;
		 gradrhoMy=gradrhoCy+gradrhoUy;


}
