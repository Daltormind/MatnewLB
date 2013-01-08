// Calculates the equilibrium value for the Composition function h 

#include "wet.h"

void wet ::equilibriumh()
{

// Calculate dCD of C

dC[k][0]=(C[d[k][0]]-C[d[k][1]])/t1/2+(C[d[k][6]]+C[d[k][8]]+C[d[k][14]]+C[d[k][16]]-C[d[k][7]]-C[d[k][9]]-C[d[k][15]]-C[d[k][17]])/t2/2;

dC[k][1]=(C[d[k][2]]-C[d[k][3]])/t1/2+(C[d[k][6]]+C[d[k][7]]+C[d[k][10]]+C[d[k][12]]-C[d[k][8]]-C[d[k][9]]-C[d[k][11]]-C[d[k][13]])/t2/2;

dC[k][2]=(C[d[k][4]]-C[d[k][5]])/t1/2+(C[d[k][10]]+C[d[k][11]]+C[d[k][14]]+C[d[k][15]]-C[d[k][12]]-C[d[k][13]]-C[d[k][16]]-C[d[k][17]])/t2/2;

// Calculate dCD of p

dp[k][0]=(p[d[k][0]]-p[d[k][1]])/t1/2+(p[d[k][6]]+p[d[k][8]]+p[d[k][14]]+p[d[k][16]]-p[d[k][7]]-p[d[k][9]]-p[d[k][15]]-p[d[k][17]])/t2/2;

dp[k][1]=(p[d[k][2]]-p[d[k][3]])/t1/2+(p[d[k][6]]+p[d[k][7]]+p[d[k][10]]+p[d[k][12]]-p[d[k][8]]-p[d[k][9]]-p[d[k][11]]-p[d[k][13]])/t2/2;

dp[k][2]=(p[d[k][4]]-p[d[k][5]])/t1/2+(p[d[k][10]]+p[d[k][11]]+p[d[k][14]]+p[d[k][15]]-p[d[k][12]]-p[d[k][13]]-p[d[k][16]]-p[d[k][17]])/t2/2;


for(a=0;a<19;a++)
{
	
	
	heq[k][a]+=(e[0][a]-u[k][0])*(dC[k][0]/cs/cs-C[k]/rho[k]*(dp[k][0]+C[k]*dmu[k][0]));
	
	heq[k][a]+=(e[1][a]-u[k][1])*(dC[k][1]/cs/cs-C[k]/rho[k]*(dp[k][1]+C[k]*dmu[k][1]));
	
	heq[k][a]+=(e[2][a]-u[k][2])*(dC[k][2]/cs/cs-C[k]/rho[k]*(dp[k][2]+C[k]*dmu[k][2]));
	
	heq[k][a]*=gamma[k][a];
	
	heq[k][a]+=C[k]*gamma[k][a];
	
}	
}