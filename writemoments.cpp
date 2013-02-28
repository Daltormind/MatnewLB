//write moments prints out the moments C p rho and mu into Matlab friendly formats


#include "wet.h"

void wet::writemoments(long int in)
{
	int i, j, h;
	ofstream file;
	char filename1[20];
		string filename;
        
        snprintf(filename1,20,"/sC%ld.m",in);			//Create a name for file that contain data
		filename=folder+filename1;
        file.open(filename.c_str());
		file.precision(4);
		
		for( h = 0 ; h < Lz ; h++) 
		{   
			file << "C" << in << "(:,:," << h+1 << ")=[" << endl;
			for( i = 0 ; i < Lx ; i++) 
			{
				for( j = 0 ; j < Ly ; j++) 
				{
					k = h + j*Lz + i*Ly*Lz;
					file << C[k] << " " ;
						
				}
				file << endl;
			}
			file <<"];" << endl;
		}
		
		file.close();
		
		snprintf(filename1,20,"/smu%ld.m",in);			//Create a name for file that contain data
		filename=folder+filename1;
        file.open(filename.c_str());
		file.precision(4);
		
		for( h = 0 ; h < Lz ; h++) 
		{   
			file << "mu" << in << "(:,:," << h+1 << ")=[" << endl;
			for( i = 0 ; i < Lx ; i++) 
			{
				for( j = 0 ; j < Ly ; j++) 
				{
					k = h + j*Lz + i*Ly*Lz;
					file << mu[k] << " " ;
						
				}
				file << endl;
			}
			file <<"];" << endl;
		}
		
		file.close();
		
		snprintf(filename1,20,"/srho%ld.m",in);			//Create a name for file that contain data
		filename=folder+filename1;
        file.open(filename.c_str());
		file.precision(4);
		
		for( h = 0 ; h < Lz ; h++) 
		{   
			file << "rho" << in << "(:,:," << h+1 << ")=[" << endl;
			for( i = 0 ; i < Lx ; i++) 
			{
				for( j = 0 ; j < Ly ; j++) 
				{
					k = h + j*Lz + i*Ly*Lz;
					file << rho[k] << " " ;
						
				}
				file << endl;
			}
			file <<"];" << endl;
		}
		
		file.close();
		
		snprintf(filename1,20,"/sp%ld.m",in);			//Create a name for file that contain data
		filename=folder+filename1;
        file.open(filename.c_str());
		file.precision(4);
		
		for( h = 0 ; h < Lz ; h++) 
		{   
			file << "p" << in << "(:,:," << h+1 << ")=[" << endl;
			for( i = 0 ; i < Lx ; i++) 
			{
				for( j = 0 ; j < Ly ; j++) 
				{
					k = h + j*Lz + i*Ly*Lz;
					file << p[k] << " " ;
						
				}
				file << endl;
			}
			file <<"];" << endl;
		}
		
		file.close();
		
		snprintf(filename1,20,"/sf%ld.m",in);			//Create a name for file that contain data
		filename=folder+filename1;
        file.open(filename.c_str());
		file.precision(4);
		
		for( h = 0 ; h < Lz ; h++) 
		{   
			file << "f" << in << "(:,:," << h+1 << ")=[" << endl;
			for( i = 0 ; i < Lx ; i++) 
			{
				for( j = 0 ; j < Ly ; j++) 
				{
					k = h + j*Lz + i*Ly*Lz;
					file << f[k] << " " ;
						
				}
				file << endl;
			}
			file <<"];" << endl;
		}
		
		file.close();
		
}