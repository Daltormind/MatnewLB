//Equilibrium computes the equilibrium values of the pressure and momentum equations 

#include "wet.h"

void wet ::equiliberiumg()

{

	geq0=gammar0*rho[k]/3.0+p[k]*4.0/9.0 +0.5*(u[k][0]*(FgrCx*gammar0+FgCx*gamma0)+u[k][1]*(FgrCy*gammar0+FgCy*gamma0));
	geq1=gammar1*rho[k]/3.0+p[k]*1.0/9.0 +0.5*(u[k][0]*(FgrCx*gammar1+FgCx*gamma1)+u[k][1]*(FgrCy*gammar1+FgCy*gamma1)-FgrC1*gammar1-FgC1*gamma1);
	geq2=gammar2*rho[k]/3.0+p[k]*1.0/9.0 +0.5*(u[k][0]*(FgrCx*gammar2+FgCx*gamma2)+u[k][1]*(FgrCy*gammar2+FgCy*gamma2)-FgrC2*gammar2-FgC2*gamma2);
	geq3=gammar3*rho[k]/3.0+p[k]*1.0/9.0 +0.5*(u[k][0]*(FgrCx*gammar3+FgCx*gamma3)+u[k][1]*(FgrCy*gammar3+FgCy*gamma3)-FgrC3*gammar3-FgC3*gamma3);
	geq4=gammar4*rho[k]/3.0+p[k]*1.0/9.0 +0.5*(u[k][0]*(FgrCx*gammar4+FgCx*gamma4)+u[k][1]*(FgrCy*gammar4+FgCy*gamma4)-FgrC4*gammar4-FgC4*gamma4);
	geq7=gammar7*rho[k]/3.0+p[k]*1.0/36.0   +0.5*(u[k][0]*(FgrCx*gammar7+FgCx*gamma7)+u[k][1]*(FgrCy*gammar7+FgCy*gamma7)-FgrC7*gammar7-FgC7*gamma7);
	geq8=gammar8*rho[k]/3.0+p[k]*1.0/36.0   +0.5*(u[k][0]*(FgrCx*gammar8+FgCx*gamma8)+u[k][1]*(FgrCy*gammar8+FgCy*gamma8)-FgrC8*gammar8-FgC8*gamma8);
	geq9=gammar9*rho[k]/3.0+p[k]*1.0/36.0   +0.5*(u[k][0]*(FgrCx*gammar9+FgCx*gamma9)+u[k][1]*(FgrCy*gammar9+FgCy*gamma9)-FgrC9*gammar9-FgC9*gamma9);
	geq10=gammar10*rho[k]/3.0+p[k]*1.0/36.0 +0.5*(u[k][0]*(FgrCx*gammar10+FgCx*gamma10)+u[k][1]*(FgrCy*gammar10+FgCy*gamma10)-FgrC10*gammar10-FgC10*gamma10);


}