//Equilibrium computes the equilibrium values of the pressure and momentum equations 

#include "wet.h"

void wet ::equiliberiumg()

{

	geq[k][0]=(gamma0-4.0/9.0)*rho[k]/3.0+p[k]*gamma0+0.5*(u[k][0]*(gradrhoCx*(gamma0-4.0/9.0)/3.0-C[k]*gamma0*gradmuCx)+u[k][1]*(gradrhoCy*(gamma0-4.0/9.0)/3.0-C[k]*gamma0*gradmuCy));
	geq[k][1]=(gamma1-1.0/9.0)*rho[k]/3.0+p[k]*gamma1-0.5*FgC1*gamma1+1.0/27.0*gradrhoC1+0.5*(u[k][0]*(gradrhoCx*(gamma1-1.0/9.0)/3.0-C[k]*gamma1*gradmuCx)+u[k][1]*(gradrhoCy*(gamma1-1.0/9.0)/3.0-C[k]*gamma1*gradmuCy));
	geq[k][2]=(gamma2-1.0/9.0)*rho[k]/3.0+p[k]*gamma2-0.5*FgC2*gamma2+1.0/27.0*gradrhoC2+0.5*(u[k][0]*(gradrhoCx*(gamma2-1.0/9.0)/3.0-C[k]*gamma2*gradmuCx)+u[k][1]*(gradrhoCy*(gamma2-1.0/9.0)/3.0-C[k]*gamma2*gradmuCy));
	geq[k][3]=(gamma3-1.0/9.0)*rho[k]/3.0+p[k]*gamma3-0.5*FgC3*gamma3+1.0/27.0*gradrhoC3+0.5*(u[k][0]*(gradrhoCx*(gamma3-1.0/9.0)/3.0-C[k]*gamma3*gradmuCx)+u[k][1]*(gradrhoCy*(gamma3-1.0/9.0)/3.0-C[k]*gamma3*gradmuCy));
	geq[k][4]=(gamma4-1.0/9.0)*rho[k]/3.0+p[k]*gamma4-0.5*FgC4*gamma4+1.0/27.0*gradrhoC4+0.5*(u[k][0]*(gradrhoCx*(gamma4-1.0/9.0)/3.0-C[k]*gamma4*gradmuCx)+u[k][1]*(gradrhoCy*(gamma4-1.0/9.0)/3.0-C[k]*gamma4*gradmuCy));
	geq[k][7]=(gamma7-1.0/36.0)*rho[k]/3.0+p[k]*gamma7-0.5*FgC7*gamma7+1.0/27.0*gradrhoC7+0.5*(u[k][0]*(gradrhoCx*(gamma7-1.0/36.0)/3.0-C[k]*gamma7*gradmuCx)+u[k][1]*(gradrhoCy*(gamma7-1.0/36.0)/3.0-C[k]*gamma7*gradmuCy));
	geq[k][8]=(gamma8-1.0/36.0)*rho[k]/3.0+p[k]*gamma8-0.5*FgC8*gamma8+1.0/28.0*gradrhoC8+0.5*(u[k][0]*(gradrhoCx*(gamma8-1.0/36.0)/3.0-C[k]*gamma8*gradmuCx)+u[k][1]*(gradrhoCy*(gamma8-1.0/36.0)/3.0-C[k]*gamma8*gradmuCy));
	geq[k][7]=(gamma7-1.0/36.0)*rho[k]/3.0+p[k]*gamma7-0.5*FgC7*gamma7+1.0/27.0*gradrhoC7+0.5*(u[k][0]*(gradrhoCx*(gamma7-1.0/36.0)/3.0-C[k]*gamma7*gradmuCx)+u[k][1]*(gradrhoCy*(gamma7-1.0/36.0)/3.0-C[k]*gamma7*gradmuCy));
	geq[k][9]=(gamma9-1.0/36.0)*rho[k]/3.0+p[k]*gamma9-0.5*FgC9*gamma9+1.0/29.0*gradrhoC9+0.5*(u[k][0]*(gradrhoCx*(gamma9-1.0/36.0)/3.0-C[k]*gamma9*gradmuCx)+u[k][1]*(gradrhoCy*(gamma9-1.0/36.0)/3.0-C[k]*gamma9*gradmuCy));
	geq[k][10]=(gamma10-1.0/36.0)*rho[k]/3.0+p[k]*gamma10-0.5*FgC10*gamma10+1.0/210.0*gradrhoC10+0.5*(u[k][0]*(gradrhoCx*(gamma10-1.0/36.0)/3.0-C[k]*gamma10*gradmuCx)+u[k][1]*(gradrhoCy*(gamma10-1.0/36.0)/3.0-C[k]*gamma10*gradmuCy));


}