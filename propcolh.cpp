//propcolh

#include "wet.h"

void wet::propcolh()
{

	
	if(mask[k]==0)
	{
		/*
		M0=M*(muh[d[k][6]]+muh[d[k][7]]+muh[d[k][8]]+muh[d[k][9]]+4.0*muh[d[k][0]]
		+4.0*muh[d[k][1]]+4.0*muh[d[k][2]]+4.0*muh[d[k][3]]-20.0*muh[k])/(6.0*dt*dt);
		*/
		            M0=M*(muh[d[k][6]]+muh[d[k][7]]+muh[d[k][8]]+muh[d[k][9]]+muh[d[k][10]]+muh[d[k][11]]+muh[d[k][12]]+muh[d[k][13]]+muh[d[k][14]]+muh[d[k][15]]+muh[d[k][16]]+muh[d[k][17]]+2.0*(muh[d[k][0]]+muh[d[k][1]]+muh[d[k][2]]+muh[d[k][3]]+muh[d[k][4]]+muh[d[k][5]])-24.0*muh[k])/(6.0*dt*dt);
	
	}
	/*
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
	*/
	
		
	
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
	
	hc[k][0]=h[k][0]-1/(tau[k]+0.5)*(h[k][0]-heq0)+dt*(0.5*M0*gamma0-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma0);
	hc[d[k][0]][1]=h[k][1]-1/(tau[k]+0.5)*(h[k][1]-heq1)+dt*(0.5*M0*gamma1-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma1+FhM1*gamma1);
	hc[d[k][1]][2]=h[k][2]-1/(tau[k]+0.5)*(h[k][2]-heq2)+dt*(0.5*M0*gamma2-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma2+FhM2*gamma2);
	hc[d[k][2]][3]=h[k][3]-1/(tau[k]+0.5)*(h[k][3]-heq3)+dt*(0.5*M0*gamma3-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma3+FhM3*gamma3);
	hc[d[k][3]][4]=h[k][4]-1/(tau[k]+0.5)*(h[k][4]-heq4)+dt*(0.5*M0*gamma4-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma4+FhM4*gamma4);
	hc[d[k][6]][7]=h[k][7]-1/(tau[k]+0.5)*(h[k][7]-heq7)+dt*(0.5*M0*gamma7-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma7+FhM7*gamma7);
	hc[d[k][7]][8]=h[k][8]-1/(tau[k]+0.5)*(h[k][8]-heq8)+dt*(0.5*M0*gamma8-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma8+FhM8*gamma8);
	hc[d[k][8]][9]=h[k][9]-1/(tau[k]+0.5)*(h[k][9]-heq9)+dt*(0.5*M0*gamma9-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma9+FhM9*gamma9);
	hc[d[k][9]][10]=h[k][10]-1/(tau[k]+0.5)*(h[k][10]-heq10)+dt*(0.5*M0*gamma10-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma10+FhM10*gamma10);

	hc[d[k][4]][5]=h[k][5]-1/(tau[k]+0.5)*(h[k][5]-heq5)+dt*(0.5*M0*gamma5-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma5+FhM5*gamma5);
	hc[d[k][5]][6]=h[k][6]-1/(tau[k]+0.5)*(h[k][6]-heq6)+dt*(0.5*M0*gamma6-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma6+FhM6*gamma6);
	hc[d[k][10]][11]=h[k][11]-1/(tau[k]+0.5)*(h[k][11]-heq11)+dt*(0.5*M0*gamma11-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma11+FhM11*gamma11);
	hc[d[k][11]][12]=h[k][12]-1/(tau[k]+0.5)*(h[k][12]-heq12)+dt*(0.5*M0*gamma12-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma12+FhM12*gamma12);
	hc[d[k][12]][13]=h[k][13]-1/(tau[k]+0.5)*(h[k][13]-heq13)+dt*(0.5*M0*gamma13-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma13+FhM13*gamma13);
	hc[d[k][13]][14]=h[k][14]-1/(tau[k]+0.5)*(h[k][14]-heq14)+dt*(0.5*M0*gamma14-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma14+FhM14*gamma14);
	hc[d[k][14]][15]=h[k][15]-1/(tau[k]+0.5)*(h[k][15]-heq15)+dt*(0.5*M0*gamma15-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma15+FhM15*gamma15);
	hc[d[k][15]][16]=h[k][16]-1/(tau[k]+0.5)*(h[k][16]-heq16)+dt*(0.5*M0*gamma16-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma16+FhM16*gamma16);
	hc[d[k][16]][17]=h[k][17]-1/(tau[k]+0.5)*(h[k][17]-heq17)+dt*(0.5*M0*gamma17-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma17+FhM17*gamma17);
	hc[d[k][17]][18]=h[k][18]-1/(tau[k]+0.5)*(h[k][18]-heq18)+dt*(0.5*M0*gamma18-(u[k][0]*FhMx+u[k][1]*FhMy+u[k][2]*FhMz)*gamma18+FhM18*gamma18);

}	
