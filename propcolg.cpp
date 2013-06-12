//Propogation and collision of g

#include "wet.h"

void wet::propcolg()
{
	g[k][0]=g[k][0]-1.0/(tau[k]+0.5)*(g[k][0]-geq0)-u[k][0]*FgMx*gamma0-u[k][1]*FgMy*gamma0+4.0/27.0*u[k][0]*gradrhoMx+4.0/27.0*u[k][1]*gradrhoMy;
	g[d[k][0]][1]=g[k][1]-1.0/(tau[k]+0.5)*(g[k][1]-geq1)-u[k][0]*FgMx*gamma1-u[k][1]*FgMy*gamma1+1.0/27.0*u[k][0]*gradrhoMx+1.0/27.0*u[k][1]*gradrhoMy;
    g[d[k][0]][1]+=FgM1*gamma1-1.0/27.0*gradrhoM1;
    g[d[k][1]][2]=g[k][2]-1.0/(tau[k]+0.5)*(g[k][2]-geq2)-u[k][0]*FgMx*gamma2-u[k][1]*FgMy*gamma2+1.0/27.0*u[k][0]*gradrhoMx+1.0/27.0*u[k][1]*gradrhoMy;
    g[d[k][1]][2]+=FgM2*gamma2-1.0/27.0*gradrhoM2;
    g[d[k][2]][3]=g[k][3]-1.0/(tau[k]+0.5)*(g[k][3]-geq3)-u[k][0]*FgMx*gamma3-u[k][1]*FgMy*gamma3+1.0/27.0*u[k][0]*gradrhoMx+1.0/27.0*u[k][1]*gradrhoMy;
    g[d[k][2]][3]+=FgM3*gamma3-1.0/27.0*gradrhoM3;
    g[d[k][3]][4]=g[k][4]-1.0/(tau[k]+0.5)*(g[k][4]-geq4)-u[k][0]*FgMx*gamma4-u[k][1]*FgMy*gamma4+1.0/27.0*u[k][0]*gradrhoMx+1.0/27.0*u[k][1]*gradrhoMy;
    g[d[k][3]][4]+=FgM4*gamma4-1.0/27.0*gradrhoM4;
    
    g[d[k][6]][7]=g[k][7]-1.0/(tau[k]+0.5)*(g[k][7]-geq7)-u[k][0]*FgMx*gamma7-u[k][1]*FgMy*gamma7+1.0/108.0*u[k][0]*gradrhoMx+1.0/108.0*u[k][1]*gradrhoMy;
    g[d[k][6]][7]+=FgM7*gamma7-1.0/108.0*gradrhoM7;
    g[d[k][7]][8]=g[k][8]-1.0/(tau[k]+0.5)*(g[k][8]-geq8)-u[k][0]*FgMx*gamma8-u[k][1]*FgMy*gamma8+1.0/108.0*u[k][0]*gradrhoMx+1.0/108.0*u[k][1]*gradrhoMy;
    g[d[k][7]][8]+=FgM8*gamma8-1.0/108.0*gradrhoM8;
    g[d[k][8]][9]=g[k][9]-1.0/(tau[k]+0.5)*(g[k][9]-geq9)-u[k][0]*FgMx*gamma9-u[k][1]*FgMy*gamma9+1.0/108.0*u[k][0]*gradrhoMx+1.0/108.0*u[k][1]*gradrhoMy;
    g[d[k][8]][9]+=FgM9*gamma9-1.0/108.0*gradrhoM9;
    g[d[k][9]][10]=g[k][10]-1.0/(tau[k]+0.5)*(g[k][10]-geq10)-u[k][0]*FgMx*gamma10-u[k][1]*FgMy*gamma10+1.0/108.0*u[k][0]*gradrhoMx+1.0/108.0*u[k][1]*gradrhoMy;
    g[d[k][9]][10]+=FgM10*gamma10-1.0/108.0*gradrhoM10;



}
