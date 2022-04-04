//Het Kanzariya 

/*
You have a binary string with length N. You are allowed to do swap() operations of two elements only if the index parity of both elements is the same. This means that: you can swap() an element at index 2, with any element at index4, 6, 8 etc. (even parity), similarly the element at index 3 can be swapped with the element at index1, 5,7,9 etc.

Ex: Given string 1110, you can swap 2nd and 4th char to get 1011. But, you can never get 1101 if you follow the swap rules.

Now, the task is to find the number of times substring 01 can occur for all such possible swaps.
Ex: 1110 does not have any substring of 01. Now you can swap2nd and 4th to get 1011, this will have ‘one’ occurrence of 01. We can now perform more swaps but we will never get any more 01 substrings here.
Input: 00100 output should be 1, for: 01010-> 2, for 10001-> 2

*/




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> even1;
vector<string> odd1;
vector<string> main_vector;
string even;
string odd;

void permute_even(string a, int l, int r)
{
    //cout << a << endl;
    int flag=1;
    string temp;
	if (l == r)
    {
        for (int i = 0; i < even1.size(); i++)
        {
            temp = even1[i];
            if(temp.compare(a) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            even1.push_back(a);
        }
    }
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);

			permute_even(a, l+1, r);

			swap(a[l], a[i]);
		}
	}
}

void permute_odd(string a, int l, int r)
{
    int flag=1;
    string temp;
	if (l == r)
    {
        for (int i = 0; i < odd1.size(); i++)
        {
            temp = odd1[i];
            if(temp.compare(a) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            odd1.push_back(a);
        }
    }
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);

			permute_odd(a, l+1, r);

			swap(a[l], a[i]);
		}
	}
}

void combine()
{
    int i,j,k,flag;
    string str,temp,temp1;
    j=0;
    k=0;
    flag = 1;
    for (i = 0; i < even1.size(); i++)
    {
        str = even1[i];
        //cout << str <<endl;
        //cout << odd <<endl;
        for(j=0;j<str.size();j++)
        {
            temp = temp + str[j];
            temp = temp + odd[j];
        }
        flag = 1;
        for (i = 0; i < main_vector.size(); i++)
        {
            temp1 = main_vector[i];
            if(temp1.compare(temp) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            //cout<< temp << endl;
            //cout <<"\n";
            main_vector.push_back(temp);

        }
        temp = "";
    }



        /////////////////////////////////////////////////////////////////////////////

    flag = 1;
    for (i = 0; i < odd1.size(); i++)
    {
        str = odd1[i];
        //cout << str <<endl;
        //cout << even <<endl;
        for(j=0;j<str.size();j++)
        {
            temp = temp + even[j];
            temp = temp + str[j];
        }
        flag = 1;
        for (i = 0; i < main_vector.size(); i++)
        {
            temp1 = main_vector[i];
            if(temp1.compare(temp) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
          //  cout<< temp << endl;
            //cout <<"\n";
            main_vector.push_back(temp);
        }
        temp = "";
    }

}

void check(string temp)
{
    int i,cou;
    cou = 0;
    for(i=0; i<temp.size()-1;i++)
    {
        if(temp[i] == '0')
        {
            if(temp[i+1] == '1')
            {
                cou++;
            }
        }
    }
    cout << temp << "->" << cou << endl;
}

int main()
{
    //string str = "1110";
    string str;
	cout<<"enter the binery number: "<<endl;
    cin>>str;
    int i,j;
    j =0;
    for(i=0;i<str.size()-1;i=i+2)
    {
            even = even + str[i];
            odd = odd + str[i+1];
    }
    //cout << even<< endl;
    //cout << odd<< endl;
    int n = even.size();
	permute_even(even, 0, n-1);
	//for (i = 0; i < even1.size(); i++)
        //cout << even1[i] << " ";
    //cout << "\n" << "\n";
	n = odd.size();
	permute_odd(odd, 0, n-1);
	//for (i = 0; i < odd1.size(); i++)
      //  cout << odd1[i] << " ";
        //cout << "\n" << "\n";

	combine();

	//for (i = 0; i < main_vector.size(); i++)
        //cout << main_vector[i] << " ";

    //cout << "\n";
    string temp;
    for(i=0; i<main_vector.size();i++)
    {
        temp = main_vector[i];
        check(temp);
    }


    return 0;
}
