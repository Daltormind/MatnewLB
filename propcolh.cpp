//propcolh

#include "wet.h"

void wet::propcolh()
{
	
	
	M0=0.5*M*(muh[d[k][6]]+muh[d[k][7]]+muh[d[k][8]]+muh[d[k][9]]+4.0*muh[d[k][0]]
	+4.0*muh[d[k][1]]+4.0*muh[d[k][2]]+4.0*muh[d[k][3]]+20.0*muh[k]);
	M1=0.5*M*(muh[d[d[k][0]][6]]+muh[d[d[k][0]][7]]+muh[d[d[k][0]][8]]+muh[d[d[k][0]][9]]+4.0*muh[d[d[k][0]][0]]
	+4.0*muh[d[d[k][0]][1]]+4.0*muh[d[d[k][0]][2]]+4.0*muh[d[d[k][0]][3]]+20.0*muh[d[k][0]]);
	M2=0.5*M*(muh[d[d[k][1]][6]]+muh[d[d[k][1]][7]]+muh[d[d[k][1]][8]]+muh[d[d[k][1]][9]]+4.0*muh[d[d[k][1]][0]]
	+4.0*muh[d[d[k][1]][1]]+4.0*muh[d[d[k][1]][2]]+4.0*muh[d[d[k][1]][3]]+20.0*muh[d[k][1]]);
	M3=0.5*M*(muh[d[d[k][2]][6]]+muh[d[d[k][2]][7]]+muh[d[d[k][2]][8]]+muh[d[d[k][2]][9]]+4.0*muh[d[d[k][2]][0]]
	+4.0*muh[d[d[k][2]][1]]+4.0*muh[d[d[k][2]][2]]+4.0*muh[d[d[k][2]][3]]+20.0*muh[d[k][2]]);
	M4=0.5*M*(muh[d[d[k][3]][6]]+muh[d[d[k][3]][7]]+muh[d[d[k][3]][8]]+muh[d[d[k][3]][9]]+4.0*muh[d[d[k][3]][0]]
	+4.0*muh[d[d[k][3]][1]]+4.0*muh[d[d[k][3]][2]]+4.0*muh[d[d[k][3]][3]]+20.0*muh[d[k][3]]);
	M7=0.5*M*(muh[d[d[k][6]][6]]+muh[d[d[k][6]][7]]+muh[d[d[k][6]][8]]+muh[d[d[k][6]][9]]+4.0*muh[d[d[k][6]][0]]
	+4.0*muh[d[d[k][6]][1]]+4.0*muh[d[d[k][6]][2]]+4.0*muh[d[d[k][6]][3]]+20.0*muh[d[k][6]]);
	M8=0.5*M*(muh[d[d[k][7]][6]]+muh[d[d[k][7]][7]]+muh[d[d[k][7]][8]]+muh[d[d[k][7]][9]]+4.0*muh[d[d[k][7]][0]]
	+4.0*muh[d[d[k][7]][1]]+4.0*muh[d[d[k][7]][2]]+4.0*muh[d[d[k][7]][3]]+20.0*muh[d[k][7]]);
	M9=0.5*M*(muh[d[d[k][8]][6]]+muh[d[d[k][8]][7]]+muh[d[d[k][8]][8]]+muh[d[d[k][8]][9]]+4.0*muh[d[d[k][8]][0]]
	+4.0*muh[d[d[k][8]][1]]+4.0*muh[d[d[k][8]][2]]+4.0*muh[d[d[k][8]][3]]+20.0*muh[d[k][8]]);
	M10=0.5*M*(muh[d[d[k][9]][6]]+muh[d[d[k][9]][7]]+muh[d[d[k][9]][8]]+muh[d[d[k][9]][9]]+4.0*muh[d[d[k][9]][0]]
	+4.0*muh[d[d[k][9]][1]]+4.0*muh[d[d[k][9]][2]]+4.0*muh[d[d[k][9]][3]]+20.0*muh[d[k][9]]);
	
	
	
	h[k][0]=h[k][0]-1/(tau+0.5)*(h[k][0]-heq[k][0])+M0*gamma0-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma0;
	h[d[k][0]][1]=h[k][1]-1/(tau+0.5)*(h[k][1]-heq[k][1])+0.5*M0*gamma1+0.5*M1*gamma1-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma1+FhM1*gamma1;
	h[d[k][1]][2]=h[k][2]-1/(tau+0.5)*(h[k][2]-heq[k][2])+0.5*M0*gamma2+0.5*M2*gamma2-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma2+FhM2*gamma2;
	h[d[k][2]][3]=h[k][3]-1/(tau+0.5)*(h[k][3]-heq[k][3])+0.5*M0*gamma3+0.5*M3*gamma3-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma3+FhM3*gamma3;
	h[d[k][3]][4]=h[k][4]-1/(tau+0.5)*(h[k][4]-heq[k][4])+0.5*M0*gamma4+0.5*M4*gamma4-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma4+FhM4*gamma4;
	h[d[k][6]][7]=h[k][7]-1/(tau+0.5)*(h[k][7]-heq[k][7])+0.5*M0*gamma7+0.5*M7*gamma7-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma7+FhM7*gamma7;
	h[d[k][7]][8]=h[k][8]-1/(tau+0.5)*(h[k][8]-heq[k][8])+0.5*M0*gamma8+0.5*M8*gamma8-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma8+FhM8*gamma8;
	h[d[k][8]][9]=h[k][9]-1/(tau+0.5)*(h[k][9]-heq[k][9])+0.5*M0*gamma9+0.5*M9*gamma9-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma9+FhM9*gamma9;
	h[d[k][9]][10]=h[k][10]-1/(tau+0.5)*(h[k][10]-heq[k][10])+0.5*M0*gamma10+0.5*M10*gamma10-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma10+FhM10*gamma10;

}	