//Propagates the fields before collision 

#include "wet.h"

void wet ::Propogation()
{
	//g propogation
	
	g[k][0]=g[k][0];
	h[k][0]=h[k][0];
	
	for(a=1;a<19;a++)
		{
			g[k][a]=g[d[k][com[a]]][a];
			f[k][a]=f[d[k][com[a]]][a];
		
		
		}
	
	g[k][1]=g[d[k][2]][1];
	g[k][2]=g[d[k][1]][2];
	
	





}