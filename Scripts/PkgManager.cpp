#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "header.h"

using namespace std;

void pkgManager(string cmd, string pkgusage) 								//Function executes system command after asking for root privilages
{
	string filename;														//package(s) name(s)
	const char* fcmd;														//pointer for the full command
	
	system("clear");
	
	if( cmd == " apt update ")												//Exutes when we want to update all installed packages(option 3)
	{
		cmd = "sudo" + cmd;
		fcmd = cmd.c_str();
		system(fcmd);
	}
	else
	{
		cout << "Please input package name: "; 
		cin >> filename;													//Pckage name is inputed and
			
		CheckPackage(filename, cmd);										//Calling function CheckPackage
		cmd = cmd + filename;												//combined with the command(options 1 and 2)
		fcmd = cmd.c_str();

		if(filename.substr(filename.find_last_of(".") + 1) == "deb"){		//if the package is a deb file	
																			//the following line needs to be added
			cmd = cmd + " ./" + filename;					
		
		}

		system(fcmd);

		presskey(pkgusage, filename);
	}
}