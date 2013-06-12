

#include "wet.h"

void wet ::equiliberiumf()

{

	feq0=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy))*gamma0;
	feq1=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC1)*gamma1;
	feq2=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC2)*gamma2;
	feq3=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC3)*gamma3;
	feq4=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC4)*gamma4;
	feq7=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC7)*gamma7;
	feq8=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC8)*gamma8;
	feq9=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC9)*gamma9;
	feq10=(rho[k]+0.5*(u[k][0]*FfCx+u[k][1]*FfCy)-0.5*FfC10)*gamma10;



}