//Edited by S.Amir Mohammad Hassanli
//Friday - 2014 19 September

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <vector>

#define V 6
#define SN -1

using namespace std;

vector <int> vec ;

void saveSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos)
 {
	if (graph [path[pos-1]][v] == 0)
		return false;
	for (int i = 0; i < pos; i++)
		if (path[i] == v)
			return false;

        return true;

  }

//******************************************************************************************

    bool hamCycleUtil(bool graph[V][V], int path[], int pos)

    {

        if (pos == V)
        {
           return true;
		}

        for (int v = 1; v < V; v++)
        {
            if (isSafe(v, graph, path, pos))
            {
                path[pos] = v;
                if (hamCycleUtil (graph, path, pos+1) == true)
                    saveSolution(path);
                path[pos] = -1;
            }
        }
        return false;
    }
//***********************************************************************************
    bool hamCycle(bool graph[V][V])

    {
        int *path = new int[V];
        for (int i = 0; i < V; i++)
            path[i] = -1;
        path[0] = 0;
		hamCycleUtil(graph, path, 1);
        return true;
    }
//**************************************************************************************8

    void saveSolution(int path[])
    {
        for (int i = 0; i < V; i++)
            vec.push_back(path[i]); // add path[i] to vector.
		vec.push_back(SN); // add special Number, defined at line 8. using to find different Hamiltonian paths.
    }

//***************************************************************************

void printSolution()
{
    cout<<"Hamiltonian path: ";
    for (int i = 0 ; i < vec.size(); i++) // vec.size() -> return size of vector, number of elements in the vector
        if(vec.at(i) != SN) // vec.at() -> return i element of vector, for ex. if vector have this elements: 1 2 3 4, vec.at(0), will return 1;
            cout<<vec.at(i)<<" ";
        else if(i != vec.size()-1 )
            cout<<endl<<"Hamiltonian path: ";

}

//***************************************************************************
 int main()
 {
	 bool graph[V][V];
	 int n;
	 ifstream fin;
	 fin.open("inputmatrix.txt",ios::in);
	 fin >> n; //node
	 for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			fin>>graph[i][j];
	 fin.close();
	 hamCycle(graph);
	 printSolution();
	 getch();
     return 0;
    }
