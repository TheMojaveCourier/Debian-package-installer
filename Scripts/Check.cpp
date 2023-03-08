#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "header.h"

using namespace std;

int ConnectionCheck() 													                        // Function checks if there is connection to the internet
{		      													                                // If there isn't the programm terminates	
	FILE *ping;

	if(!(ping = popen("/sbin/route -n | grep -c '^0\\.0\\.0\\.0'","r")))						//Pinging to find a connection
	{
	    return 1;
	}
	
	unsigned int connection;

	fscanf(ping,"%u",&connection);

	if (connection == 1)												                        //Connection found programm procceds normaly
	{
		cout << "\nConnection successful \n\n";
	}
	else														                                //Connection failed programm terminates
	{
		presskey("Error: Failed to connect to server. Please check your connection and try again \n\n"," ");
		
	}

	pclose(ping);
	return 0;
}

int CheckPackage(string pkgName, string pkgUsage)
{
	pkgName = pkgName + " -h > null 2 > null";							                                        //The command to check if package exists, null exists to suppress terminal output
	const char* pkgn = pkgName.c_str();								                                            //Converting strings to constant character pointers
	const char* pkgU =pkgUsage.c_str();
	int pkgExists = system(pkgn);									                                            //If pkgE = 0 the package exist if pkg > 0 packge doesnt exist if pkgE < 0 IDK
	string answer;											                                                    //Simple variable to get an answer
	
	//cout << "\nDebug line: Comand is " << pkgU << " Package Exists(0 = yes, >0 = no) " << pkgExists << endl;	//Debug line delete later
	
	if(pkgExists == 0 && strstr(pkgU, "apt install ") )						                                    //What happens when package exists and the first option is selected
	{
		cout << "\n\nPackage already exists, would you like to upgdate? Y or N \n\n";		                    //Menu for when the package name inputed in option 1 is already
		cin >> answer;										                                                   //installed and then asks if the user wants to upgrade the package
			
		while(answer != "n" || answer != "y" || answer != "Y" || answer != "N")			                       //Simple while loop to get the answer
		{
			if(answer == "N" || answer == "n")						                                           //Process terminates if answer is NO
			{
				system("clear");
				presskey("Process terminated \n\n", " ");
			}
			else if(answer == "Y" || answer == "y")						                                       //If answer is YES programm continius normally
			{
				return 0;
			}
			else
			{
				cout << "Please input Y or N(not case sencitive)";			                                    //Clear input to prevent infinite loops in case of the wrong type
				cin.clear();								                                                   //of variable is inputes
				cin.ignore(100, '\n');														
	    		cin >> answer;
	   		}
		}
	}
	else if(pkgExists > 0 && strstr(pkgU, " apt remove "))						                                //If option 2 and package doesn't exist presskey function is called
	{												                                                            //and the programm terminates as there is no package to uninstall
		presskey("Package doen't exist or has already been removed \n\n", " ");
	}
	else												                                                        // If none of the above the programm continius normally
	{
		return 0;
	}
	return 0;
}