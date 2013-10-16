//Compute all the mixed difference differentials needed in collission.cpp

#include "wet.h"

void wet ::Computemixedd()
{
	dC[k][0]+=(4*C[d[k][0]]-3*C[d[k][1]]-C[d[d[k][0]][0]])/2/t1
	+(4*C[d[k][6]]-3*C[d[k][9]-C[d[d[k][6]][6]]+4*C[d[k][8]]-3*C[d[k][7]-C[d[d[k][8]][8]]+
	4*C[d[k][14]]-3*C[d[k][17]-C[d[d[k][14]][14]]+4*C[d[k][16]]-3*C[d[k][15]-C[d[d[k][16]][16]])/2/t2;
	
	drho[k][0]+=(4*rho[d[k][0]]-3*rho[d[k][1]]-rho[d[d[k][0]][0]])/2/t1
	+(4*rho[d[k][6]]-3*rho[d[k][9]-rho[d[d[k][6]][6]]+4*rho[d[k][8]]-3*rho[d[k][7]-rho[d[d[k][8]][8]]+
	4*rho[d[k][14]]-3*rho[d[k][17]-rho[d[d[k][14]][14]]+4*rho[d[k][16]]-3*rho[d[k][15]-rho[d[d[k][16]][16]])/2/t2;

	dp[k][0]+=(4*p[d[k][0]]-3*p[d[k][1]]-p[d[d[k][0]][0]])/2/t1
	+(4*p[d[k][6]]-3*p[d[k][9]-p[d[d[k][6]][6]]+4*p[d[k][8]]-3*p[d[k][7]-p[d[d[k][8]][8]]+
	4*p[d[k][14]]-3*p[d[k][17]-p[d[d[k][14]][14]]+4*p[d[k][16]]-3*p[d[k][15]-p[d[d[k][16]][16]])/2/t2;
	
	dmux[k]+=(4*mu[d[k][0]]-3*mu[d[k][1]]-mu[d[d[k][0]][0]])/2/t1
	+(4*mu[d[k][6]]-3*mu[d[k][9]-mu[d[d[k][6]][6]]+4*mu[d[k][8]]-3*mu[d[k][7]-mu[d[d[k][8]][8]]+
	4*mu[d[k][14]]-3*mu[d[k][17]-mu[d[d[k][14]][14]]+4*mu[d[k][16]]-3*mu[d[k][15]-mu[d[d[k][16]][16]])/2/t2;
	
	dgamma[k][a]+=((4*gamma[d[k][0]][a]-3*gamma[d[k][1]][a]-gamma[d[d[k][0]][0]][a])/2/t1
	+(4*gamma[d[k][6]][a]-3*gamma[d[k][9][a]-gamma[d[d[k][6]][6]][a]+4*gamma[d[k][8]][a]
	-3*gamma[d[k][7][a]-gamma[d[d[k][8]][8]][a]+4*gamma[d[k][14]][a]-3*gamma[d[k][17][a]
	-gamma[d[d[k][14]][14]][a]+4*gamma[d[k][16]][a]-3*gamma[d[k][15][a]
	-gamma[d[d[k][16]][16]][a])/2/t2)*(e[0][a]-u[k][a]);
	
	
	








}