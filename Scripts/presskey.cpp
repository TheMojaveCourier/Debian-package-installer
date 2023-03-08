#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include "header.h"

using namespace std;

void presskey(string pkgusage, string filename)						//Function prevents the command line interface from imidiatly shutting down
{													                //when it is done by requesting user input in order to finish
	cout << "\n" << pkgusage << filename;							//Also displays the equivilant success message
	cout << "\n\nPress ENTER key to exit!";

	cin.get();
	cin.clear();
	cin.ignore();

	exit(0);

}