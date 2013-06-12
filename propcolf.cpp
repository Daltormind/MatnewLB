
#include "wet.h"

void wet::propcolf()
{
	f[k][0]=f[k][0]-1.0/(tau[k]+0.5)*(f[k][0]-feq0)-u[k][0]*FfMx*gamma0-u[k][1]*FfMy*gamma0;
	f[d[k][0]][1]=f[k][1]-1.0/(tau[k]+0.5)*(f[k][1]-feq1)-u[k][0]*FfMx*gamma1-u[k][1]*FfMy*gamma1+FfM1*gamma1;
    f[d[k][1]][2]=f[k][2]-1.0/(tau[k]+0.5)*(f[k][2]-feq2)-u[k][0]*FfMx*gamma2-u[k][1]*FfMy*gamma2+FfM2*gamma2;
    f[d[k][2]][3]=f[k][3]-1.0/(tau[k]+0.5)*(f[k][3]-feq3)-u[k][0]*FfMx*gamma3-u[k][1]*FfMy*gamma3+FfM3*gamma3;
    f[d[k][3]][4]=f[k][4]-1.0/(tau[k]+0.5)*(f[k][4]-feq4)-u[k][0]*FfMx*gamma4-u[k][1]*FfMy*gamma4+FfM4*gamma4;
    f[d[k][6]][7]=f[k][7]-1.0/(tau[k]+0.5)*(f[k][7]-feq7)-u[k][0]*FfMx*gamma7-u[k][1]*FfMy*gamma7+FfM7*gamma7;
    f[d[k][7]][8]=f[k][8]-1.0/(tau[k]+0.5)*(f[k][8]-feq8)-u[k][0]*FfMx*gamma8-u[k][1]*FfMy*gamma8+FfM8*gamma8;
    f[d[k][8]][9]=f[k][9]-1.0/(tau[k]+0.5)*(f[k][9]-feq9)-u[k][0]*FfMx*gamma9-u[k][1]*FfMy*gamma9+FfM9*gamma9;
    f[d[k][9]][10]=f[k][10]-1.0/(tau[k]+0.5)*(f[k][10]-feq10)-u[k][0]*FfMx*gamma10-u[k][1]*FfMy*gamma10+FfM10*gamma10;




}