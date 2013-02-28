//Computes the adjacents to every point

#include "wet.h"

void wet::neibour(int k)

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
	
	computecoordinates(k);
	
	for(a=0;a<Q-1;a++)
	{
	
	
	
	x=xk+geo[a][0];
	y=yk+geo[a][1];
	z=zk+geo[a][2];
	
	
	x=mod(x,Lx);
	y=mod(y,Ly);
	z=mod(z,Lz);
	
	
	
	d[k][a]=z+y*Lz+x*Ly*Lz;
	
	
	
	}
	 

	









} 