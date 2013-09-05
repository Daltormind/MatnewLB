//writevelocity outputs the velocity

#include "wet.h"

void wet::writevelocity(int in)

{
	int q, j, n;
	ofstream file;
	char filename1[20];
		string filename;
        

        
        snprintf(filename1,20,"/sux%ld.m",in);			//Create a name for file that contain data
		filename=folder+filename1;
        file.open(filename.c_str());
		file.precision(16);
		
		for( n = 0 ; n < Lz ; n++) 
		{   
			file << "u" << i << "t" << in << "(:,:," << n+1 << ")=[" << endl;
			for( q = 0 ; q < Lx ; q++) 
			{
				for( j = 0 ; j < Ly ; j++) 
				{
					k = n + j*Lz + q*Ly*Lz;
					file << ux << " " ;
						
				}
				file << endl;
			}
			file <<"];" << endl;
		}
		
		file.close();
		
		
}