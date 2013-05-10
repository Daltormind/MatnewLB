//Propogation and collision of g

#include "wet.h"

void wet::propcolg()
{
	g[k][0]=g[k][0]-1.0/(tau+0.5)*(g[k][0]-geq0)-u[k][0]*FgMx*gamma0-u[k][1]*FgMy*gamma0+4.0/27.0*u[k][0]*gradrhoMx+4.0/27.0*u[k][1]*gradrhoMy;
	g[k][1]=g[k][1]-1.0/(tau+0.5)*(g[k][1]-geq1)-u[k][1]*FgMx*gamma1-u[k][1]*FgMy*gamma1+1.0/27.0*u[k][0]*gradrhoMx+1.0/27.0*u[k][1]*gradrhoMy;

}