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
	
	inputfile >> Neqst;
    inputfile.ignore(250,'\n');
    cout << "Neqst " << Neqst << endl;
    
    inputfile >> wrtst;
    inputfile.ignore(250,'\n');
    cout << "wrtst " << wrtst << endl;
	
	inputfile >> dimensions;
    inputfile.ignore(250,'\n');
    cout << "dimensions " << dimensions << endl;
    
    inputfile >> Lx >> Ly >> Lz;
    inputfile.ignore(250,'\n');
    cout << "Simulation Box Size " << Lx << " " << Ly << " "<< Lz << endl;
    
    inputfile >> rho1 >> rho2 ;
    inputfile.ignore(250,'\n');
    cout << "rho1 rho2 are " << rho1 << " " << rho2 << endl;
    
    inputfile >> ep ;
    inputfile.ignore(250,'\n');
    cout << "epsilon is " << ep << endl;
    
    inputfile >> B >> BA ;
    inputfile.ignore(250,'\n');
    cout << "B and BA are " << B << " " << BA << endl;
    
    inputfile >> M ;
    inputfile.ignore(250,'\n');
    cout << "M is " << M  << endl;
    
    inputfile >> theta ;
    inputfile.ignore(250,'\n');
    cout << "theta is " << theta  << endl;
    
    inputfile >> tau1 >> tau2 ;
    inputfile.ignore(250,'\n');
    cout << "tau1 and tau2 are " << tau1 << " " << tau2 << endl;
    
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
    
	//-------------------------------Get inputs from surf.par-----------------------
    
    inputfile.open("surf.par");
    
    if (!inputfile) {
		cout << "Can't open the input file surf.par " << endl;
	}
	
	inputfile >> xs >> ys >> zs ;
    inputfile.ignore(250,'\n');
    cout << "Surface position " << xs << " " << ys << " " << zs << endl;
    
    inputfile >> wx >> wy >> wz;
    inputfile.ignore(250,'\n');
    cout << "surface width " << wx << " " << wy << " " << wz << endl;
    
    inputfile.close();





}