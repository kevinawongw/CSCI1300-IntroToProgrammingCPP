#include <iostream>
#include <math.h>
using namespace std;



int checkLeapYear(int year)
{
    if(year==1500)
        return 1;
    if (year>1582){
	if (year%400==0 && year%100==0)
	{
        return 1;
	}
	if (year%4==0 && year%100!=0)
	{
	    return 1;
	}
    if (year%4==0 && year%100==0)
	{
	    return 0;
	}
	else
	{
	    return 0;
	}
}
else
{return 0;
}
}
 
int main(){
int year;
cout << "Enter a year: ";
cin >> year;
checkLeapYear(year);
}