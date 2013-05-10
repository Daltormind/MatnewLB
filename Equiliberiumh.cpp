// Calculates the equilibrium value for the Composition function h 

#include "wet.h"

void wet ::equiliberiumh()
{







heq[k][0]=gamma0*C[k]+1.0/2.0*(u[k][0]*FhCx+u[k][1]*FhCy)*gamma0;
heq[k][1]=gamma1*C[k]-1.0/2.0*(FhC1-u[k][0]*FhCx+u[k][1]*FhCy)*gamma1;
heq[k][2]=gamma2*C[k]-1.0/2.0*(FhC2-u[k][0]*FhCx+u[k][1]*FhCy)*gamma2;
heq[k][3]=gamma3*C[k]-1.0/2.0*(FhC3-u[k][0]*FhCx+u[k][1]*FhCy)*gamma3;
heq[k][4]=gamma4*C[k]-1.0/2.0*(FhC4-u[k][0]*FhCx+u[k][1]*FhCy)*gamma4;
heq[k][7]=gamma7*C[k]-1.0/2.0*(FhC7-u[k][0]*FhCx+u[k][1]*FhCy)*gamma7;
heq[k][8]=gamma8*C[k]-1.0/2.0*(FhC8-u[k][0]*FhCx+u[k][1]*FhCy)*gamma8;
heq[k][9]=gamma9*C[k]-1.0/2.0*(FhC9-u[k][0]*FhCx+u[k][1]*FhCy)*gamma9;
heq[k][10]=gamma10*C[k]-1.0/2.0*(FhC10-u[k][0]*FhCx+u[k][1]*FhCy)*gamma10;
	
	

	


}