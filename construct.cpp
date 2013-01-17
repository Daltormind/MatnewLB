//Constructor for class wet

#include "wet.h"


wet::wet(void) 
	
{

	
	
	
	
	
	readinput();
	
	string command="mkdir " + folder;
    cout <<"String command is equal to " << command << endl;
    system(command.c_str());
	
	initialise();

	


}