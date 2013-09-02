//Propogation and collision of g

#include "wet.h"

void wet::propcolg()
{
	double gforce0,gforce1,gforce2,gforce3,gforce4,gforce7,gforce8,gforce9,gforce10,gforce6,gforce5,gforce11,gforce12,gforce13,gforce14,gforce15,gforce16,gforce17,gforce18;

  gforce0=-u[k][0]*(FgrMx*gammar0+FgMx*gamma0)-u[k][1]*(FgrMy*gammar0+FgMy*gamma0) -u[k][2]*(FgrMz*gammar0+FgMz*gamma0);
  gforce1=-u[k][0]*(FgrMx*gammar1+FgMx*gamma1)-u[k][1]*(FgrMy*gammar1+FgMy*gamma1) -u[k][2]*(FgrMz*gammar1+FgMz*gamma1)+FgM1*gamma1+FgrM1*gammar1;
  gforce2=-u[k][0]*(FgrMx*gammar2+FgMx*gamma2)-u[k][1]*(FgrMy*gammar2+FgMy*gamma2)-u[k][2]*(FgrMz*gammar2+FgMz*gamma2)+FgM2*gamma2+FgrM2*gammar2;
  gforce3=-u[k][0]*(FgrMx*gammar3+FgMx*gamma3)-u[k][1]*(FgrMy*gammar3+FgMy*gamma3)-u[k][2]*(FgrMz*gammar3+FgMz*gamma3)+FgM3*gamma3+FgrM3*gammar3;
  gforce4=-u[k][0]*(FgrMx*gammar4+FgMx*gamma4)-u[k][1]*(FgrMy*gammar4+FgMy*gamma4)-u[k][2]*(FgrMz*gammar4+FgMz*gamma4)+FgM4*gamma4+FgrM4*gammar4;
  gforce7=-u[k][0]*(FgrMx*gammar7+FgMx*gamma7)-u[k][1]*(FgrMy*gammar7+FgMy*gamma7)-u[k][2]*(FgrMz*gammar7+FgMz*gamma7)+FgM7*gamma7+FgrM7*gammar7;
  gforce8=-u[k][0]*(FgrMx*gammar8+FgMx*gamma8)-u[k][1]*(FgrMy*gammar8+FgMy*gamma8)-u[k][2]*(FgrMz*gammar8+FgMz*gamma8)+FgM8*gamma8+FgrM8*gammar8;
  gforce9=-u[k][0]*(FgrMx*gammar9+FgMx*gamma9)-u[k][1]*(FgrMy*gammar9+FgMy*gamma9)-u[k][2]*(FgrMz*gammar9+FgMz*gamma9)+FgM9*gamma9+FgrM9*gammar9;
  gforce10=-u[k][0]*(FgrMx*gammar10+FgMx*gamma10)-u[k][1]*(FgrMy*gammar10+FgMy*gamma10)-u[k][2]*(FgrMz*gammar10+FgMz*gamma10)+FgM10*gamma10+FgrM10*gammar10;
  
  gforce5=-u[k][0]*(FgrMx*gammar5+FgMx*gamma5)-u[k][1]*(FgrMy*gammar5+FgMy*gamma5)-u[k][2]*(FgrMz*gammar5+FgMz*gamma5)+FgM5*gamma5+FgrM5*gammar5;
  gforce6=-u[k][0]*(FgrMx*gammar6+FgMx*gamma6)-u[k][1]*(FgrMy*gammar6+FgMy*gamma6)-u[k][2]*(FgrMz*gammar6+FgMz*gamma6)+FgM6*gamma6+FgrM6*gammar6;
  gforce11=-u[k][0]*(FgrMx*gammar11+FgMx*gamma11)-u[k][1]*(FgrMy*gammar11+FgMy*gamma11)-u[k][2]*(FgrMz*gammar11+FgMz*gamma11)+FgM11*gamma11+FgrM11*gammar11;
  gforce12=-u[k][0]*(FgrMx*gammar12+FgMx*gamma12)-u[k][1]*(FgrMy*gammar12+FgMy*gamma12)-u[k][2]*(FgrMz*gammar12+FgMz*gamma12)+FgM12*gamma12+FgrM12*gammar12;
  gforce13=-u[k][0]*(FgrMx*gammar13+FgMx*gamma13)-u[k][1]*(FgrMy*gammar13+FgMy*gamma13)-u[k][2]*(FgrMz*gammar13+FgMz*gamma13)+FgM13*gamma13+FgrM13*gammar13;
  gforce14=-u[k][0]*(FgrMx*gammar14+FgMx*gamma14)-u[k][1]*(FgrMy*gammar14+FgMy*gamma14)-u[k][2]*(FgrMz*gammar14+FgMz*gamma14)+FgM14*gamma14+FgrM14*gammar14;
  gforce15=-u[k][0]*(FgrMx*gammar15+FgMx*gamma15)-u[k][1]*(FgrMy*gammar15+FgMy*gamma15)-u[k][2]*(FgrMz*gammar15+FgMz*gamma15)+FgM15*gamma15+FgrM15*gammar15;
  gforce16=-u[k][0]*(FgrMx*gammar16+FgMx*gamma16)-u[k][1]*(FgrMy*gammar16+FgMy*gamma16)-u[k][2]*(FgrMz*gammar16+FgMz*gamma16)+FgM16*gamma16+FgrM16*gammar16;
  gforce17=-u[k][0]*(FgrMx*gammar17+FgMx*gamma17)-u[k][1]*(FgrMy*gammar17+FgMy*gamma17)-u[k][2]*(FgrMz*gammar17+FgMz*gamma17)+FgM17*gamma17+FgrM17*gammar17;
  gforce18=-u[k][0]*(FgrMx*gammar18+FgMx*gamma18)-u[k][1]*(FgrMy*gammar18+FgMy*gamma18)-u[k][2]*(FgrMz*gammar18+FgMz*gamma18)+FgM18*gamma18+FgrM18*gammar18;

  
  gc[k][0]=g[k][0]-1.0/(tau[k]+0.5)*(g[k][0]-geq0)+dt*gforce0;
  gc[d[k][0]][1]=g[k][1]-1.0/(tau[k]+0.5)*(g[k][1]-geq1)+dt*gforce1;
  gc[d[k][1]][2]=g[k][2]-1.0/(tau[k]+0.5)*(g[k][2]-geq2)+dt*gforce2;
  gc[d[k][2]][3]=g[k][3]-1.0/(tau[k]+0.5)*(g[k][3]-geq3)+dt*gforce3;
  gc[d[k][3]][4]=g[k][4]-1.0/(tau[k]+0.5)*(g[k][4]-geq4)+dt*gforce4;
    
  gc[d[k][6]][7]=g[k][7]-1.0/(tau[k]+0.5)*(g[k][7]-geq7)+dt*gforce7;
  gc[d[k][7]][8]=g[k][8]-1.0/(tau[k]+0.5)*(g[k][8]-geq8)+dt*gforce8;
  gc[d[k][8]][9]=g[k][9]-1.0/(tau[k]+0.5)*(g[k][9]-geq9)+dt*gforce9;
  gc[d[k][9]][10]=g[k][10]-1.0/(tau[k]+0.5)*(g[k][10]-geq10)+dt*gforce10;
  
  gc[d[k][4]][5]=g[k][5]-1.0/(tau[k]+0.5)*(g[k][5]-geq5)+dt*gforce5;
  gc[d[k][5]][6]=g[k][6]-1.0/(tau[k]+0.5)*(g[k][6]-geq6)+dt*gforce6;
  gc[d[k][10]][11]=g[k][11]-1.0/(tau[k]+0.5)*(g[k][11]-geq11)+dt*gforce11;
  gc[d[k][11]][12]=g[k][12]-1.0/(tau[k]+0.5)*(g[k][12]-geq12)+dt*gforce12;
  gc[d[k][12]][13]=g[k][13]-1.0/(tau[k]+0.5)*(g[k][13]-geq13)+dt*gforce13;
  gc[d[k][13]][14]=g[k][14]-1.0/(tau[k]+0.5)*(g[k][14]-geq14)+dt*gforce14;
  gc[d[k][14]][15]=g[k][15]-1.0/(tau[k]+0.5)*(g[k][15]-geq15)+dt*gforce15;
  gc[d[k][15]][16]=g[k][16]-1.0/(tau[k]+0.5)*(g[k][16]-geq16)+dt*gforce16;
  gc[d[k][16]][17]=g[k][17]-1.0/(tau[k]+0.5)*(g[k][17]-geq17)+dt*gforce17;
  gc[d[k][17]][18]=g[k][18]-1.0/(tau[k]+0.5)*(g[k][18]-geq18)+dt*gforce18;




}
