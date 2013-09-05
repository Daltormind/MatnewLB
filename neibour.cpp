//Computes the adjacents to every point

#include "wet.h"

void wet::neibour()

{
	
	
	
	const int geo[18][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1}
							,{0,0,-1},{1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0}
							,{0,1,1},{0,-1,1},{0,1,-1},{0,-1,-1},{1,0,1},
							{-1,0,1},{1,0,-1},{-1,0,-1}};
							
	/*
	
	const int geo[8][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},
						{1,1,0},{-1,1,0},{1,-1,0},{-1,-1,0}
							};						
	*/
	
	
	
	
	
	int x,y,z; //Intigers which give the offset of each point
	
	
	
	for(k=k1;k<k2;k++)
	{
	
	computecoordinates(k);
	
	for(a=0;a<Q-1;a++)
	{
	
	
	
	x=xk+geo[a][0];
	y=yk+geo[a][1];
	z=zk+geo[a][2];
	
	
	//x=mod(x,Lx);
	y=mod(y,Ly);
	z=mod(z,Lz);
	
	
	
	d[k][a]=z+y*Lz+x*Ly*Lz;
	}
	
	if(k<k1+Ly*Lz or k>=k2-Ly*Lz)
	{
		for(a=0;a<Q-1;a++)
	{
		x=xk+2*geo[a][0];
		y=yk+2*geo[a][1];
		z=zk+2*geo[a][2];
	
	
	//x=mod(x,Lx);
	y=mod(y,Ly);
	z=mod(z,Lz);
	
	
	
	d[d[k][a]][a]=z+y*Lz+x*Ly*Lz;
	}
	}
	
	
	}
	 

	









} 