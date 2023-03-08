#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>

#include "header.h"

using namespace std;

int main()
{

	int usage;	 																//The options
	string pkgUsage;															//The system command 

	cout << "\t\tUbuntu Package Manager CMD Edition ver 0.1.24\n\n";
	cout << "Select usage: \n\n 1) Install/Update package \n\n 2) Remove package \n\n 3) Update all packages \n\n 4) Exit \n\n Usage: ";	//Basic command line menu
	cin >> usage;

	while(usage != 1 || usage != 2 || usage != 3 || usage != 4)
	{
	    switch(usage)
	    {
		    case 1:
		    	ConnectionCheck();
		       	pkgUsage = "Succesfully installed/updated package(s) ";
			   	pkgManager("apt install ", pkgUsage); 
			   
		    case 2:
			   	pkgUsage = "Succesfully removed package ";
			   	pkgManager(" apt remove ", pkgUsage); 
			    
			    
		    case 3:
			    ConnectionCheck();
			    pkgUsage = "Succesfully updated package ";
			    pkgManager(" apt update ", pkgUsage);
			    
		    case 4:
			    exit(0);																				//If option 4 is selected the programterminates
			    
		    default:
			    cout << "\nPlease input number 1,2,3 or 4 for the corisponding option \n\nUsage:";		//Message that is displayed when the user
																										//doesnt select one of the available options and loop restarts
	    }	
	    cin.clear();																					//Clears the last input so if a char or string is insertedinstead
	    cin.ignore(100, '\n');																			//of an int the loop won't brake. 
	    cin >> usage;																					//It ignores the rest 100 character.
	}

	return 0;

}