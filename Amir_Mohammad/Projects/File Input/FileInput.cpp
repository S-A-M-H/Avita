// This is a simple code for getting input using files in C++ language.
// Written by S.Amir Mohammad Hassanli
// Saturday - 2014 20 September

#include <iostream>
#include <string>
#include <fstream>
#define V 6

using namespace std;

int main()
{

	string myArray[V];
    ifstream myFile;
    myFile.open("InputString.txt");
    int i = 0;
    if(myFile.is_open())
    {
        while(!myFile.eof() && i != V)
        {
            getline(myFile, myArray[i]);
            i++;
        }
    }
    myFile.close();

	for (int j = 0 ; j < V ; j ++)
		cout<<myArray[j]<<endl;
return 0;
}
