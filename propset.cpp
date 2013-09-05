
#include "wet.h"

void wet ::propset()
{
/*
gamma0 = 4.0/9.0 * (1.0 - 1.5*(ux[k]*ux[k] + uy[k]*uy[k]));
  
  gamma1 = 1.0/9.0 * (1.0 + 3.0*ux[k] + 3.0*ux[k]*ux[k] - 1.5*uy[k]*uy[k]);
  
  gamma3 = 1.0/9.0*(1.0+3.0*uy[k]+3.0*uy[k]*uy[k]-1.5*ux[k]*ux[k]);
  
  gamma2 = 1.0/9.0*(1.0-3.0*ux[k]+3.0*ux[k]*ux[k]-1.5*uy[k]*uy[k]);
  
  gamma4 = 1.0/9.0*(1.0-3.0*uy[k]+3.0*uy[k]*uy[k]-1.5*ux[k]*ux[k]);
  
  gamma7 = 1.0/36.0*(1.0+3.0*(ux[k]+uy[k]+ux[k]*ux[k]+uy[k]*uy[k])+9.0*ux[k]*uy[k]);
  
  gamma8 = 1.0/36.0*(1.0+3.0*(-ux[k]+uy[k]+ux[k]*ux[k]+uy[k]*uy[k])-9.0*ux[k]*uy[k]);
  
  gamma10 = 1.0/36.0*(1.0+3.0*(-ux[k]-uy[k]+ux[k]*ux[k]+uy[k]*uy[k])+9.0*ux[k]*uy[k]);
  
  gamma9 = 1.0/36.0*(1.0+3.0*(ux[k]-uy[k]+ux[k]*ux[k]+uy[k]*uy[k])-9.0*ux[k]*uy[k]);

M0=M*(muh[d[k][6]]+muh[d[k][7]]+muh[d[k][8]]+muh[d[k][9]]+4.0*muh[d[k][0]]
		+4.0*muh[d[k][1]]+4.0*muh[d[k][2]]+4.0*muh[d[k][3]]-20.0*muh[k])/(6.0*dt*dt);
		
*/		

h0[k]=hc0[k];//+dt*0.5*M0*gamma0;
h1[k]=hc1[k];//+dt*0.5*M0*gamma1;
h2[k]=hc2[k];//+dt*0.5*M0*gamma2;
h3[k]=hc3[k];//+dt*0.5*M0*gamma3;
h4[k]=hc4[k];//+dt*0.5*M0*gamma4;
h5[k]=hc5[k];//+dt*0.5*M0*gamma5;
h6[k]=hc6[k];//+dt*0.5*M0*gamma6;
h7[k]=hc7[k];//+dt*0.5*M0*gamma7;
h8[k]=hc8[k];//+dt*0.5*M0*gamma8;
h9[k]=hc9[k];//+dt*0.5*M0*gamma9;
h10[k]=hc10[k];//+dt*0.5*M0*gamma10;
h11[k]=hc11[k];//+dt*0.5*M0*gamma11;
h12[k]=hc12[k];//+dt*0.5*M0*gamma12;
h13[k]=hc13[k];//+dt*0.5*M0*gamma13;
h14[k]=hc14[k];//+dt*0.5*M0*gamma14;
h15[k]=hc15[k];//+dt*0.5*M0*gamma15;
h16[k]=hc16[k];//+dt*0.5*M0*gamma16;
h17[k]=hc17[k];//+dt*0.5*M0*gamma17;
h18[k]=hc18[k];//+dt*0.5*M0*gamma18;

g0[k]=gc0[k];
g1[k]=gc1[k];
g2[k]=gc2[k];
g3[k]=gc3[k];
g4[k]=gc4[k];
g5[k]=gc5[k];
g6[k]=gc6[k];
g7[k]=gc7[k];
g8[k]=gc8[k];
g9[k]=gc9[k];
g10[k]=gc10[k];
g11[k]=gc11[k];
g12[k]=gc12[k];
g13[k]=gc13[k];
g14[k]=gc14[k];
g15[k]=gc15[k];
g16[k]=gc16[k];
g17[k]=gc17[k];
g18[k]=gc18[k];

}