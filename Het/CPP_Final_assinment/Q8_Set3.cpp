//Het Kanzariya

/*
There are two processes, A and B, that can access a common variable x. They can access it in sequence, A first and then B, or B first then A. But in one day they access it only once. A logbook is maintained by the OS showing which process accessed x when.
    You got a series of entries of the log, but you want to make sure that this log has not been altered by anyone. Your output is the answer to the question: Is the log valid or not?
Ex: Input: AB, output: Yes
       Input: ABAABB, output: No

*/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string a;
    int flag = 1,i;
    cout<<"enter the string in A and B:"<<endl;
    cin>>a;
    for(i=0;i<a.length();i=i+2)
    {
        if(a[i]== 'A' && a[i+1] == 'B')
        {
            flag = 1;
        }
        else if(a[i]== 'B' && a[i+1] == 'A')
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
}
