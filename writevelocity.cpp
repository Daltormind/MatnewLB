//writevelocity outputs the velocity

#include "wet.h"

void wet::writevelocity(int in)

{
	int q, j, h;
	ofstream file;
	char filename1[20];
		string filename;
        
        for(i=0;i<3;i++)
        {
        
        snprintf(filename1,20,"/su%dt%ld.m",i,in);			//Create a name for file that contain data
		filename=folder+filename1;
        file.open(filename.c_str());
		file.precision(4);
		
		for( h = 0 ; h < Lz ; h++) 
		{   
			file << "u" << i << "t" << in << "(:,:," << h+1 << ")=[" << endl;
			for( q = 0 ; q < Lx ; q++) 
			{
				for( j = 0 ; j < Ly ; j++) 
				{
					k = h + j*Lz + q*Ly*Lz;
					file << u[k][i] << " " ;
						
				}
				file << endl;
			}
			file <<"];" << endl;
		}
		
		file.close();
		}
		
}