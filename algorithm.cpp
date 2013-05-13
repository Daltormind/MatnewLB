//algorithm


#include "wet.h"


void wet::algorithm()

{





		for(st=1;st<=Neqst;st++)
		{

            computemoments();



		for(k=k1;k<k2;k++)
		{
			diffCD();
			diffBD();
			centralforce();
			equiliberiumg();
            equiliberiumh();
            propcolh();
            propcolg();



		}




		if(st%wrtst==0)
		{
		//computefreeenergy();
		//cout << "t = " << st << " El=" << El << " Eg=" << Eg << " Ei=" << Ei  << " Et=" << Et << endl;
		writemoments(st);

		writevelocity(st);
		}


		}

}
