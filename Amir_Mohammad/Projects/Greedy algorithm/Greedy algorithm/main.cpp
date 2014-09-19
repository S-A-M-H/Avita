// Written by S.Amir Mohammad Hassanli
// Thursday, July 03, 2014

#include <iostream> // using std outputs like cout and cin.

using namespace std; // defenition place of cout and cin

void _memset(int n , int *arry , int value) // to set first value of varuables in dynamic arrays.
{
	for(int i = 0 ; i < n ; i ++)
		arry[i] = value;
}

void Bublesort( int n , int *profitarry , int *timearry) // bublesort algorithm used for sorting works by profit.
{
	for(int i = 0 ; i < n-1 ; i ++)
		for(int j = 0; j < n - i - 1 ; j ++)
			if(profitarry[j] > profitarry[j+1])
			{
				int temp1 = profitarry[j];
				profitarry[j] = profitarry[j+1];
				profitarry[j+1] = temp1;
				int temp2 = timearry[j];  // change time of a work when a work have been moved(sorted)
				timearry[j] = timearry[j+1];
				timearry[j+1] = temp2;
			}
}

void choose(int n , int *profitarray , int *timearry , int *time , int *profit) // main part of program that select posible jobs that have most profit.
{
	time[0] = timearry[n-1];
	profit[0] = profitarray[n-1];

	int _time = 1; // an itireator to the 'time' array(not timearry). used for pointing to next free block in 'time' and 'profit' array.
	for(int i = n-2 ; i >= 0  ; i--)
	{
		bool posibility = true; // to check is this job possible to do or not.
		for(int j = 0 ; j < n ; j++)
			if(timearry[i] == time[j]) // if we had a job with same time in our selected jobs array('time' and 'profit' arrays) this job is inpossible to do.
				posibility = false;
		if(posibility == true) // if we didnt have a job with same time, we select this job.
		{
			time[_time] = timearry[i];
			profit[_time] = profitarray[i];
			_time++;
		}
	}
}

int main()
{
	int n; // number of jobs
	int totalprofit = 0; // total and most profit that we will get  it with these algorithm

	cin >> n; // enter numbers of jobs

	int *workstime = new int [n]; // dynamic array with new command for profit of jobs
	int *worksprofit = new int [n]; // dynamic array with new command for time of jobs
	int *time = new int [n]; // dynamic array with new command for time of selected jobs
	int *profit = new int [n]; // dynamic array with new command for profit of selected jobs

	_memset(n , time , 0); // set first(defined) value of time array
	_memset(n , profit , -1); // set first(defined) value of profit array

	for(int i = 0; i < n ; i++)
		cin >>workstime[i] >> worksprofit[i]; // get jobs profit and time form user;

	Bublesort(n ,worksprofit , workstime); // sort works with profit parameter that explained at line 11

	for(int i = 0; i < n ; i ++)
		cout<<i+1<<"- "<< worksprofit[i]<<" => " << workstime[i] <<endl; // show the sorted values

	choose(n , worksprofit , workstime , time , profit); //choose the possible and best jobs to do that explained at line 26
	cout<<endl;
	for(int i = 0 ; i < n ; i ++)
		if(time[i] != 0) // check if time[i] is not EQU to defined value.
		{
			totalprofit += profit[i];
			cout<<i+1 <<"- "<<"profit = "<<profit[i] <<" time = "<<time[i]<<endl; // show the selected jobs
		}
	cout<<endl<<"totlal profit is "<<totalprofit<<endl; // show total profit that we will get if we do that jobs, also its best value of profit that we can have with given jobs



	delete[] worksprofit; // make free the RAM
	delete[] workstime; // make free the RAM
	delete[] time; // make free the RAM
	delete[] profit; // make free the RAM

	cin.ignore(); // ignoring "\n" in st::cin buffer
	cin.get(); // wait for getting a char from keyboard. you can also use system("PAUSE > NULL"); or getch(); (getch function is an old and undrestandard function in conio_h header file and i never recomed this for use).
	return 0; // if our program finish successfully, it will return 0(also defined value EXIT_SUCCSE in DEV)
}
