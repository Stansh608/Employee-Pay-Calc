#include <fstream>
#include <iostream>
#include<cstdlib>
using namespace std;

//function to ensure that worked hours cannot be negative.
int validating(float job[7],float rate)
{
int i;
if(rate<=0)
{
	return 0;
}
for(i=0;i<7;i++)
{
	if(job[i]<0)
	return 0;
}
return 1;
}

//The main function
int main()
{
ifstream inFile("Employee.txt");
ofstream outFile("outFile.txt");
ofstream error_file("errorFile.txt");
float working_hrs[7],total_hrs,t1,t2,federal,state,Union,gross,net,rate;
int a;
char name[100];

//Reading the employee data from the Employee.txt
if(inFile.is_open())

{
	//writing the output
	outFile<<"Name Total_hours Hourly_rate Federal State Union Gross_pay Net_pay"<<endl;
	outFile<<"-------------------------------------------------------------------------------------"<<endl;
while(!inFile.eof())
{
	inFile>>name;
	for(a=0;a<7;a++)
{
inFile>>working_hrs[a];
}
inFile>>rate;
//passing parameter to validate
if(validating(working_hrs,rate))//if true
{
total_hrs=0;
//summing weekly hrs
for(a=0;a<7;a++)
{
total_hrs+=working_hrs[a];
}
if(total_hrs>40 && total_hrs<=60)
{
t1=total_hrs-40;
t2=0;
}
else if(total_hrs>60)
{
t1=20;
t2=total_hrs-60;
}
else
{
t1=0;t2=0; 
}
//calculation of the gross
gross=total_hrs*rate;
gross+=t1*rate*.5;
gross+=t2*rate;
federal=.18*gross;
state=.045*gross;
Union=.02*gross;
net=gross-(federal+state+Union);
outFile<<name<<"\t "<<total_hrs<<"\t "<<rate<<"\t "<<federal<<"\t "<<state<<"\t "<<Union<<"\t "<<gross<<"\t "<<net<<endl;
}
else
{
//in case of invalid data,, the line below execute
error_file<<name<<" has invalid data"<<endl;
}

}
}
//closing all the opened files
inFile.close();
outFile.close();
error_file.close();

//This will be written to the console once the program successfully runs
cout<<"Records has been written on outFile.txt and errorFile.txt\nKindly check.\n"<<endl;
}
