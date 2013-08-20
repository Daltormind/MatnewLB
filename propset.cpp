
#include "wet.h"

void wet ::propset()
{

gamma0 = 4.0/9.0 * (1.0 - 1.5*(u[k][0]*u[k][0] + u[k][1]*u[k][1]));
  
  gamma1 = 1.0/9.0 * (1.0 + 3.0*u[k][0] + 3.0*u[k][0]*u[k][0] - 1.5*u[k][1]*u[k][1]);
  
  gamma3 = 1.0/9.0*(1.0+3.0*u[k][1]+3.0*u[k][1]*u[k][1]-1.5*u[k][0]*u[k][0]);
  
  gamma2 = 1.0/9.0*(1.0-3.0*u[k][0]+3.0*u[k][0]*u[k][0]-1.5*u[k][1]*u[k][1]);
  
  gamma4 = 1.0/9.0*(1.0-3.0*u[k][1]+3.0*u[k][1]*u[k][1]-1.5*u[k][0]*u[k][0]);
  
  gamma7 = 1.0/36.0*(1.0+3.0*(u[k][0]+u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])+9.0*u[k][0]*u[k][1]);
  
  gamma8 = 1.0/36.0*(1.0+3.0*(-u[k][0]+u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])-9.0*u[k][0]*u[k][1]);
  
  gamma10 = 1.0/36.0*(1.0+3.0*(-u[k][0]-u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])+9.0*u[k][0]*u[k][1]);
  
  gamma9 = 1.0/36.0*(1.0+3.0*(u[k][0]-u[k][1]+u[k][0]*u[k][0]+u[k][1]*u[k][1])-9.0*u[k][0]*u[k][1]);

M0=M*(muh[d[k][6]]+muh[d[k][7]]+muh[d[k][8]]+muh[d[k][9]]+4.0*muh[d[k][0]]
		+4.0*muh[d[k][1]]+4.0*muh[d[k][2]]+4.0*muh[d[k][3]]-20.0*muh[k])/(6.0*dt*dt);

h[k][0]=hc[k][0]+dt*0.5*M0*gamma0;
h[k][1]=hc[k][1]+dt*0.5*M0*gamma1;
h[k][2]=hc[k][2]+dt*0.5*M0*gamma2;
h[k][3]=hc[k][3]+dt*0.5*M0*gamma3;
h[k][4]=hc[k][4]+dt*0.5*M0*gamma4;
h[k][5]=hc[k][5]+dt*0.5*M0*gamma5;
h[k][6]=hc[k][6]+dt*0.5*M0*gamma6;
h[k][7]=hc[k][7]+dt*0.5*M0*gamma7;
h[k][8]=hc[k][8]+dt*0.5*M0*gamma8;
h[k][9]=hc[k][9]+dt*0.5*M0*gamma9;
h[k][10]=hc[k][10]+dt*0.5*M0*gamma10;
h[k][11]=hc[k][11]+dt*0.5*M0*gamma11;
h[k][12]=hc[k][12]+dt*0.5*M0*gamma12;
h[k][13]=hc[k][13]+dt*0.5*M0*gamma13;
h[k][14]=hc[k][14]+dt*0.5*M0*gamma14;
h[k][15]=hc[k][15]+dt*0.5*M0*gamma15;
h[k][16]=hc[k][16]+dt*0.5*M0*gamma16;
h[k][17]=hc[k][17]+dt*0.5*M0*gamma17;
h[k][18]=hc[k][18]+dt*0.5*M0*gamma18;

g[k][0]=gc[k][0];
g[k][1]=gc[k][1];
g[k][2]=gc[k][2];
g[k][3]=gc[k][3];
g[k][4]=gc[k][4];
g[k][5]=gc[k][5];
g[k][6]=gc[k][6];
g[k][7]=gc[k][7];
g[k][8]=gc[k][8];
g[k][9]=gc[k][9];
g[k][10]=gc[k][10];
g[k][11]=gc[k][11];
g[k][12]=gc[k][12];
g[k][13]=gc[k][13];
g[k][14]=gc[k][14];
g[k][15]=gc[k][15];
g[k][16]=gc[k][16];
g[k][17]=gc[k][17];
g[k][18]=gc[k][18];

}