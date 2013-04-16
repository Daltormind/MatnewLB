// Calculates the equilibrium value for the Composition function h 

#include "wet.h"

void wet ::equiliberiumh()
{


for(k=k1;k<k2;k++)
{
if(mask[k]!=28)
{

	// Calculate dCD of C
	if(mask[k]!=28)
	{
	if(mask[k]==0 or mask[k]==2)
	{
	if(dimensions==3)
	{
	dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][6]]+C[d[k][8]]+C[d[k][14]]+C[d[k][16]]-C[d[k][7]]-C[d[k][9]]-C[d[k][15]]-C[d[k][17]])*t2/2;

	dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][6]]+C[d[k][7]]+C[d[k][10]]+C[d[k][12]]-C[d[k][8]]-C[d[k][9]]-C[d[k][11]]-C[d[k][13]])*t2/2;

	dC[k][2]=(C[d[k][4]]-C[d[k][5]])*t1/2+(C[d[k][10]]+C[d[k][11]]+C[d[k][14]]+C[d[k][15]]-C[d[k][12]]-C[d[k][13]]-C[d[k][16]]-C[d[k][17]])*t2/2;
	}
	
	if(dimensions==2)
	{
	dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][8]]+C[d[k][6]]-C[d[k][7]]-C[d[k][9]])*t2/2;

	dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][6]]+C[d[k][7]]-C[d[k][8]]-C[d[k][9]])*t2/2;
	
	dC[k][2]=0.0;
	}
	
	
	// Calculate dCD of p
	
	if(dimensions==3)
	{
	dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][6]]+p[d[k][8]]+p[d[k][14]]+p[d[k][16]]-p[d[k][7]]-p[d[k][9]]-p[d[k][15]]-p[d[k][17]])*t2/2;

	dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]+p[d[k][10]]+p[d[k][12]]-p[d[k][8]]-p[d[k][9]]-p[d[k][11]]-p[d[k][13]])*t2/2;

	dp[k][2]=(p[d[k][4]]-p[d[k][5]])*t1/2+(p[d[k][10]]+p[d[k][11]]+p[d[k][14]]+p[d[k][15]]-p[d[k][12]]-p[d[k][13]]-p[d[k][16]]-p[d[k][17]])*t2/2;
	}
	
	if(dimensions==2)
	{
	dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

	dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
	dp[k][2]=0.0;
	}
	} //Calculate differentials of p and C
	else
	{
		if(dimensions==2)
		{
			if(mask[d[k][0]]==28)
			{
				dC[k][0]=0.0;
				
				dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][6]]+C[d[k][7]]-C[d[k][8]]-C[d[k][9]])*t2/2;

				dC[k][2]=0.0;
			}
			
			if(mask[d[k][1]]==28)
			{
				dC[k][0]=0.0;
				
				dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][6]]+C[d[k][7]]-C[d[k][8]]-C[d[k][9]])*t2/2;

				dC[k][2]=0.0;
			}
			
			if(mask[d[k][2]]==28)
			{
				dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][6]]+C[d[k][8]]-C[d[k][7]]-C[d[k][9]])*t2/2;
				
				dC[k][1]=0.0;

				dC[k][2]=0.0;
			}
			
			if(mask[d[k][3]]==28)
			{
				dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][6]]+C[d[k][8]]-C[d[k][7]]-C[d[k][9]])*t2/2;
				
				dC[k][1]=0.0;

				dC[k][2]=0.0;
			}
			
			/*
			if(mask[d[k][6]]==28)
			{
				dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][8]]-C[d[k][7]])*t2/2;

				dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][7]]-C[d[k][8]])*t2/2;

				dC[k][2]=0.0;
			}
			
			if(mask[d[k][7]]==28)
			{
				dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][6]]-C[d[k][9]])*t2/2;

				dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][6]]-C[d[k][9]])*t2/2;

				dC[k][2]=0.0;
			}
			
			if(mask[d[k][8]]==28)
			{
				dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][6]]-C[d[k][9]])*t2/2;

				dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][6]]-C[d[k][9]])*t2/2;

				dC[k][2]=0.0;
			}
			
			if(mask[d[k][9]]==28)
			{
				dC[k][0]=(C[d[k][0]]-C[d[k][1]])*t1/2+(C[d[k][8]]-C[d[k][7]])*t2/2;

				dC[k][1]=(C[d[k][2]]-C[d[k][3]])*t1/2+(C[d[k][7]]-C[d[k][8]])*t2/2;

				dC[k][2]=0.0;
			}
			
			
			if(mask[d[k][10]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			
			if(mask[d[k][11]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			
			if(mask[d[k][12]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			
			if(mask[d[k][13]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			
			if(mask[d[k][14]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			
			if(mask[d[k][15]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			
			if(mask[d[k][16]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			
			if(mask[d[k][17]]==28)
			{
				dp[k][0]=(p[d[k][0]]-p[d[k][1]])*t1/2+(p[d[k][8]]+p[d[k][6]]-p[d[k][7]]-p[d[k][9]])*t2/2;

				dp[k][1]=(p[d[k][2]]-p[d[k][3]])*t1/2+(p[d[k][6]]+p[d[k][7]]-p[d[k][8]]-p[d[k][9]])*t2/2;
	
				dp[k][2]=0.0;
			}
			*/
		}
	}
	
	

	for(a=0;a<Q;a++)
	{
	
		heq[k][a]=0.0;
		
		heq[k][a]-=(e[a][0]-u[k][0])*(dC[k][0]-C[k]/rho[k]/cs2*(dp[k][0]+C[k]*dmu[k][0]));
	
		heq[k][a]-=(e[a][1]-u[k][1])*(dC[k][1]-C[k]/rho[k]/cs2*(dp[k][1]+C[k]*dmu[k][1]));
	
		heq[k][a]-=(e[a][2]-u[k][2])*(dC[k][2]-C[k]/rho[k]/cs2*(dp[k][2]+C[k]*dmu[k][2]));
	
		heq[k][a]/=cs2;
	
		
	
		heq[k][a]*=gamma[k][a];
	
		heq[k][a]+=C[k]*gamma[k][a];
		
		
	
	
	
	}	

}
}

}

}