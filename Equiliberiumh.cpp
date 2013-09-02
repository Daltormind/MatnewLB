// Calculates the equilibrium value for the Composition function h 

#include "wet.h"

void wet ::equiliberiumh()
{







heq0=gamma0*C[k]+0.5*dt*(u[k][0]*FhCx+u[k][1]*FhCy+u[k][2]*FhCz)*gamma0;
 heq1=gamma1*C[k]-0.5*dt*(FhC1-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma1;
heq2=gamma2*C[k]-0.5*dt*(FhC2-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma2;
heq3=gamma3*C[k]-0.5*dt*(FhC3-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma3;
heq4=gamma4*C[k]-0.5*dt*(FhC4-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma4;
heq7=gamma7*C[k]-0.5*dt*(FhC7-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma7;
heq8=gamma8*C[k]-0.5*dt*(FhC8-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma8;
heq9=gamma9*C[k]-0.5*dt*(FhC9-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma9;
heq10=gamma10*C[k]-0.5*dt*(FhC10-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma10;

heq5=gamma5*C[k]-0.5*dt*(FhC5-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma5;
heq6=gamma6*C[k]-0.5*dt*(FhC6-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma6;
heq11=gamma11*C[k]-0.5*dt*(FhC11-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma11;
heq12=gamma12*C[k]-0.5*dt*(FhC12-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma12;
heq13=gamma13*C[k]-0.5*dt*(FhC13-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma13;
heq14=gamma14*C[k]-0.5*dt*(FhC14-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma14;
heq15=gamma15*C[k]-0.5*dt*(FhC15-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma15;
heq16=gamma16*C[k]-0.5*dt*(FhC16-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma16;
heq17=gamma17*C[k]-0.5*dt*(FhC17-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma17;
heq18=gamma18*C[k]-0.5*dt*(FhC18-u[k][0]*FhCx-u[k][1]*FhCy-u[k][2]*FhCz)*gamma18;
	

	


}
