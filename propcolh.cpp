//propcolh

#include "wet.h"

void wet::propcolh()
{

	
	if(mask[k]==0)
	{
		M0=M*(muh[d[k][6]]+muh[d[k][7]]+muh[d[k][8]]+muh[d[k][9]]+4.0*muh[d[k][0]]
		+4.0*muh[d[k][1]]+4.0*muh[d[k][2]]+4.0*muh[d[k][3]]-20.0*muh[k])/(6.0*dt*dt);
	}
	else if(mask[k]==1)
	{
		
		
		M0=1.0/3.0*M*(muh[d[k][7]] + muh[d[k][9]] + 4.0*muh[d[k][1]]
	 + 2.0*muh[d[k][2]] + 2.0*muh[d[k][3]] - 10.0*muh[k]);
	}
	
	else if(mask[k]==2)
	{
		
		
		M0=1.0/3.0*M*(muh[d[k][6]] + muh[d[k][8]] + 4.0*muh[d[k][0]]
	+2.0*muh[d[k][2]] + 2.0*muh[d[k][3]] - 10.0*muh[k]);

		
	}
	
	else if(mask[k]==3)
	{
		
		
		M0=1.0/3.0*M*(muh[d[k][8]] + muh[d[k][9]] + 4.0*muh[d[k][3]]
	+2.0*muh[d[k][0]] + 2.0*muh[d[k][1]] - 10.0*muh[k]);

		
	}
	
	else if(mask[k]==4)
	{
		
		
		M0=1.0/3.0*M*(muh[d[k][6]] + muh[d[k][7]] + 4.0*muh[d[k][2]]
	+2.0*muh[d[k][0]] + 2.0*muh[d[k][1]] - 10.0*muh[k]);

		
	}
	
	else if(mask[k]==7)
	{
		
		
		M0=1.0/6.0*M*(muh[d[k][8]] + 2.0*muh[d[k][9]] + muh[d[k][7]]+ 4.0*muh[d[k][3]] + 4.0*muh[d[k][2]]
	+4.0*muh[d[k][0]] + 4.0*muh[d[k][1]] - 20.0*muh[k]);

		
	}
	else if(mask[k]==8)
	{
		

		M0=1.0/6.0*M*(2.0*muh[d[k][8]] + muh[d[k][9]] + muh[d[k][6]]+ 4.0*muh[d[k][3]] + 4.0*muh[d[k][2]]
	+4.0*muh[d[k][0]] + 4.0*muh[d[k][1]] - 20.0*muh[k]);
		
	}
	
	else if(mask[k]==9)
	{
		
		
		M0=1.0/6.0*M*(muh[d[k][6]] + 2.0*muh[d[k][7]] + muh[d[k][9]]+ 4.0*muh[d[k][3]] + 4.0*muh[d[k][2]]
	+4.0*muh[d[k][0]] + 4.0*muh[d[k][1]] - 20.0*muh[k]);

		
	}
	
	else if(mask[k]==10)
	{
		

		M0=1.0/6.0*M*(muh[d[k][8]] + 2.0*muh[d[k][6]] + muh[d[k][7]]+ 4.0*muh[d[k][3]] + 4.0*muh[d[k][2]]
	+4.0*muh[d[k][0]] + 4.0*muh[d[k][1]] - 20.0*muh[k]);
	}
	
	
		
	
	/*
	else
	{
	
	if(mask[d[k][0]]==1)
	{
		M1=1.0/6.0*M*(muh[d[d[k][0]][7]]+muh[d[d[k][0]][7]]+muh[d[d[k][0]][9]]+muh[d[d[k][0]][9]]+4.0*muh[d[d[k][0]][1]]
	+4.0*muh[d[d[k][0]][1]]+4.0*muh[d[d[k][0]][2]]+4.0*muh[d[d[k][0]][3]]-20.0*muh[d[k][0]]);
	
	}
	
	if(mask[d[k][6]]==1)
	{
		M7=1.0/6.0*M*(muh[d[d[k][6]][7]]+muh[d[d[k][6]][7]]+muh[d[d[k][6]][9]]+muh[d[d[k][6]][9]]+4.0*muh[d[d[k][6]][1]]
	+4.0*muh[d[d[k][6]][1]]+4.0*muh[d[d[k][6]][2]]+4.0*muh[d[d[k][6]][3]]-20.0*muh[d[k][6]]);
	
	}
	
	if(mask[d[k][8]]==1)
	{
		M9=1.0/6.0*M*(muh[d[d[k][8]][9]]+muh[d[d[k][8]][7]]+muh[d[d[k][8]][7]]+muh[d[d[k][8]][9]]+4.0*muh[d[d[k][8]][1]]
	+4.0*muh[d[d[k][8]][1]]+4.0*muh[d[d[k][8]][2]]+4.0*muh[d[d[k][8]][3]]-20.0*muh[d[k][8]]);
	
	}
	
	if(mask[d[k][7]]==2)
	{
		M8=1.0/6.0*M*(muh[d[d[k][7]][6]]+muh[d[d[k][7]][6]]+muh[d[d[k][7]][8]]+muh[d[d[k][7]][8]]+4.0*muh[d[d[k][7]][0]]
	+4.0*muh[d[d[k][7]][0]]+4.0*muh[d[d[k][7]][2]]+4.0*muh[d[d[k][7]][3]]-20.0*muh[d[k][7]]);
	
	}
	
	if(mask[d[k][9]]==2)
	{
		M10=1.0/6.0*M*(muh[d[d[k][9]][6]]+muh[d[d[k][9]][6]]+muh[d[d[k][9]][8]]+muh[d[d[k][9]][8]]+4.0*muh[d[d[k][9]][0]]
	+4.0*muh[d[d[k][9]][0]]+4.0*muh[d[d[k][9]][2]]+4.0*muh[d[d[k][9]][3]]-20.0*muh[d[k][9]]);
	
	}
	
	if(mask[d[k][1]]==2)
	{
		M2=1.0/6.0*M*(muh[d[d[k][1]][6]]+muh[d[d[k][1]][6]]+muh[d[d[k][1]][8]]+muh[d[d[k][1]][8]]+4.0*muh[d[d[k][1]][0]]
	+4.0*muh[d[d[k][1]][0]]+4.0*muh[d[d[k][1]][2]]+4.0*muh[d[d[k][1]][3]]-20.0*muh[d[k][1]]);
	
	}
	}
	
	*/
	
	hc[k][0]=h[k][0]-1/(tau[k]+0.5)*(h[k][0]-heq0)+dt*(0.5*M0*gamma0-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma0);
	hc[d[k][0]][1]=h[k][1]-1/(tau[k]+0.5)*(h[k][1]-heq1)+dt*(0.5*M0*gamma1-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma1+FhM1*gamma1);
	hc[d[k][1]][2]=h[k][2]-1/(tau[k]+0.5)*(h[k][2]-heq2)+dt*(0.5*M0*gamma2-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma2+FhM2*gamma2);
	hc[d[k][2]][3]=h[k][3]-1/(tau[k]+0.5)*(h[k][3]-heq3)+dt*(0.5*M0*gamma3-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma3+FhM3*gamma3);
	hc[d[k][3]][4]=h[k][4]-1/(tau[k]+0.5)*(h[k][4]-heq4)+dt*(0.5*M0*gamma4-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma4+FhM4*gamma4);
	hc[d[k][6]][7]=h[k][7]-1/(tau[k]+0.5)*(h[k][7]-heq7)+dt*(0.5*M0*gamma7-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma7+FhM7*gamma7);
	hc[d[k][7]][8]=h[k][8]-1/(tau[k]+0.5)*(h[k][8]-heq8)+dt*(0.5*M0*gamma8-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma8+FhM8*gamma8);
	hc[d[k][8]][9]=h[k][9]-1/(tau[k]+0.5)*(h[k][9]-heq9)+dt*(0.5*M0*gamma9-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma9+FhM9*gamma9);
	hc[d[k][9]][10]=h[k][10]-1/(tau[k]+0.5)*(h[k][10]-heq10)+dt*(0.5*M0*gamma10-(u[k][0]*FhMx+u[k][1]*FhMy)*gamma10+FhM10*gamma10);

}	
