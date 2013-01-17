//Read input takes input to set up initial conditions

#include "wet.h"


void wet::readinput()
{
	ifstream inputfile;
	
	//------------------------------Get inputs from wet.par-----------------------------
	
	inputfile.open("wet.par");
	
	if (!inputfile) {
		cout << "Can't open the input file wet.par " << endl;
	}
	
	inputfile >> dimensions;
    inputfile.ignore(250,'\n');
    cout << "dimensions " << dimensions << endl;
    
    inputfile >> Lx >> Ly >> Lz;
    inputfile.ignore(250,'\n');
    cout << "Simulation Box Size " << Lx << Ly << Lz << endl;
    
    inputfile >> rho1 >> rho2 ;
    inputfile.ignore(250,'\n');
    cout << "rho1 rho2 are " << rho1 << rho2 << endl;
    
    inputfile >> kappa ;
    inputfile.ignore(250,'\n');
    cout << "kappa is " << kappa << endl;
    
    inputfile >> B ;
    inputfile.ignore(250,'\n');
    cout << "B is " << B << endl;
    
    inputfile >> folder;
    inputfile.ignore(250,'\n');
    cout << "Folder is " << folder << endl;
    
    inputfile.close();
    
    //-------------------------------Get inputs from LGconfig.par-----------------------
    
    inputfile.open("LGconfig.par");
    
    if (!inputfile) {
		cout << "Can't open the input file LGconfig.par " << endl;
	}
	
	inputfile >> xcentre >> ycentre >> zcentre ;
    inputfile.ignore(250,'\n');
    cout << "Drop centre " << xcentre << " " << ycentre << " " << zcentre << endl;
    
    inputfile >> R;
    inputfile.ignore(250,'\n');
    cout << "Droplet Radius " << R << endl;
    
    inputfile >> ux >> uy >> uz;
    inputfile.ignore(250,'\n');
    cout << "Initial Drop velocity " << ux << " " << uy << " " << uz << endl;
    
    inputfile.close();
    






}