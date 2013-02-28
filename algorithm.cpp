//algorithm


#include "wet.h"


void wet::algorithm()

{
		
		
		 int ch=50;
	
	
		for(st=1;st<=Neqst;st++)
		{
			//ch=ch+1;
			//computemoments();
			
			
			
			//writemoments(st);
			
			
			
			
			//writevelocity(st);
			
			diffMD();
			
			//writevelocity(ch);
			
			propcolg();
			
			propcolh();
			
			mach();
			
		for(k=k1;k<k2;k++)
		{
			for(a=0;a<Q;a++)
			{
				
		
				h[k][a]=hc[k][a];
				g[k][a]=gc[k][a];
		
			}

		}
		
		computemoments();
		if(st%wrtst==0)
		{
		writemoments(st);
		writevelocity(st);
		}
		equiliberiumg();
		equiliberiumh();
		
		}

}                                                                                             