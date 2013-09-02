//Equilibrium computes the equilibrium values of the pressure and momentum equations 

#include "wet.h"

void wet ::equiliberiumg()

{

	geq0=gammar0*rho[k]/3.0 + p[k]*t0 +0.5*dt*(u[k][0]*(FgrCx*gammar0 + FgCx*gamma0) + u[k][1]*(FgrCy*gammar0 + FgCy*gamma0) + u[k][2]*(FgrCz*gammar0 + FgCz*gamma0));
	geq1=gammar1*rho[k]/3.0 + p[k]*t1 +0.5*dt*(u[k][0]*(FgrCx*gammar1 + FgCx*gamma1) + u[k][1]*(FgrCy*gammar1 + FgCy*gamma1)+ u[k][2]*(FgrCz*gammar1 + FgCz*gamma1) - FgrC1*gammar1 - FgC1*gamma1);
	geq2=gammar2*rho[k]/3.0 + p[k]*t1 +0.5*dt*(u[k][0]*(FgrCx*gammar2 + FgCx*gamma2) + u[k][1]*(FgrCy*gammar2 + FgCy*gamma2)+ u[k][2]*(FgrCz*gammar2 + FgCz*gamma2) - FgrC2*gammar2 - FgC2*gamma2);
	geq3=gammar3*rho[k]/3.0 + p[k]*t1 +0.5*dt*(u[k][0]*(FgrCx*gammar3+FgCx*gamma3)+u[k][1]*(FgrCy*gammar3+FgCy*gamma3)+ u[k][2]*(FgrCz*gammar3 + FgCz*gamma3)-FgrC3*gammar3-FgC3*gamma3);
	geq4=gammar4*rho[k]/3.0 + p[k]*t1 +0.5*dt*(u[k][0]*(FgrCx*gammar4+FgCx*gamma4)+u[k][1]*(FgrCy*gammar4+FgCy*gamma4)+ u[k][2]*(FgrCz*gammar4 + FgCz*gamma4)-FgrC4*gammar4-FgC4*gamma4);
	geq7=gammar7*rho[k]/3.0 + p[k]*t2   +0.5*dt*(u[k][0]*(FgrCx*gammar7+FgCx*gamma7)+u[k][1]*(FgrCy*gammar7+FgCy*gamma7)+ u[k][2]*(FgrCz*gammar7 + FgCz*gamma7)-FgrC7*gammar7-FgC7*gamma7);
	geq8=gammar8*rho[k]/3.0 + p[k]*t2   +0.5*dt*(u[k][0]*(FgrCx*gammar8+FgCx*gamma8)+u[k][1]*(FgrCy*gammar8+FgCy*gamma8)+ u[k][2]*(FgrCz*gammar8 + FgCz*gamma8)-FgrC8*gammar8-FgC8*gamma8);
	geq9=gammar9*rho[k]/3.0 + p[k]*t2   +0.5*dt*(u[k][0]*(FgrCx*gammar9+FgCx*gamma9)+u[k][1]*(FgrCy*gammar9+FgCy*gamma9)+ u[k][2]*(FgrCz*gammar9 + FgCz*gamma9)-FgrC9*gammar9-FgC9*gamma9);
	geq10=gammar10*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar10+FgCx*gamma10)+u[k][1]*(FgrCy*gammar10+FgCy*gamma10)+ u[k][2]*(FgrCz*gammar10 + FgCz*gamma10)-FgrC10*gammar10-FgC10*gamma10);

	geq5=gammar5*rho[k]/3.0 + p[k]*t1 +0.5*dt*(u[k][0]*(FgrCx*gammar5+FgCx*gamma5)+u[k][1]*(FgrCy*gammar5+FgCy*gamma5)+ u[k][2]*(FgrCz*gammar5 + FgCz*gamma5)-FgrC5*gammar5-FgC5*gamma5);
	geq6=gammar6*rho[k]/3.0 + p[k]*t1 +0.5*dt*(u[k][0]*(FgrCx*gammar6+FgCx*gamma6)+u[k][1]*(FgrCy*gammar6+FgCy*gamma6)+ u[k][2]*(FgrCz*gammar6 + FgCz*gamma6)-FgrC6*gammar6-FgC6*gamma6);

	geq11=gammar11*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar11+FgCx*gamma11)+u[k][1]*(FgrCy*gammar11+FgCy*gamma11)+ u[k][2]*(FgrCz*gammar11 + FgCz*gamma11)-FgrC11*gammar11-FgC11*gamma11);
	geq12=gammar12*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar12+FgCx*gamma12)+u[k][1]*(FgrCy*gammar12+FgCy*gamma12)+ u[k][2]*(FgrCz*gammar12 + FgCz*gamma12)-FgrC12*gammar12-FgC12*gamma12);
	geq13=gammar13*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar13+FgCx*gamma13)+u[k][1]*(FgrCy*gammar13+FgCy*gamma13)+ u[k][2]*(FgrCz*gammar13 + FgCz*gamma13)-FgrC13*gammar13-FgC13*gamma13);
	geq14=gammar14*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar14+FgCx*gamma14)+u[k][1]*(FgrCy*gammar14+FgCy*gamma14)+ u[k][2]*(FgrCz*gammar14 + FgCz*gamma14)-FgrC14*gammar14-FgC14*gamma14);
	geq15=gammar15*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar15+FgCx*gamma15)+u[k][1]*(FgrCy*gammar15+FgCy*gamma15)+ u[k][2]*(FgrCz*gammar15 + FgCz*gamma15)-FgrC15*gammar15-FgC15*gamma15);
	geq16=gammar16*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar16+FgCx*gamma16)+u[k][1]*(FgrCy*gammar16+FgCy*gamma16)+ u[k][2]*(FgrCz*gammar16 + FgCz*gamma16)-FgrC16*gammar16-FgC16*gamma16);
	geq17=gammar17*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar17+FgCx*gamma17)+u[k][1]*(FgrCy*gammar17+FgCy*gamma17)+ u[k][2]*(FgrCz*gammar17 + FgCz*gamma17)-FgrC17*gammar17-FgC17*gamma17);
	geq18=gammar18*rho[k]/3.0 + p[k]*t2 +0.5*dt*(u[k][0]*(FgrCx*gammar18+FgCx*gamma18)+u[k][1]*(FgrCy*gammar18+FgCy*gamma18)+ u[k][2]*(FgrCz*gammar18 + FgCz*gamma18)-FgrC18*gammar18-FgC18*gamma18);

}
