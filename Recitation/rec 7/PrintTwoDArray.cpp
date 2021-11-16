#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void printTwoDArray ( int output[][5], int length){
    if (length == 0){
        cout << "0" << endl;
    }
    else if (length < 0){
        cout <<"-1" << endl;
    }
    else {
        for(int i=0; i<length; i++)    // loops on the rows.
	{
	    	for(int j=0; j<5; j++) // loops on the columns
		    {
			    if (i==length)
			    {
			        cout << output[i][j];
			    }
			    else
			    {
			        cout << output[i][j];
			        cout << ",";
			    }
		    }
		    cout << endl;
	    }
    }
}