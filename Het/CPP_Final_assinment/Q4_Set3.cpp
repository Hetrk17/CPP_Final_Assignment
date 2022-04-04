//Het Kanzariya
/*
In this question, you are given a binary string of length T. Now you need to create two permutations of this string: S1 and S2 such that the ‘longest common subsequence’ between the two newly created strings is smallest.

Ex: Given string: 101, you can find S1: 110 and S2: 011, The longest common subsequence between S1 and S2 is 11 and the length is 2. There cannot be any two permutations of the given string where the LCS is less than 2
Ex: Given 0111, then S1 should be: 1101, and S2: 0111, the smallest LCS will be 2 char long.

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string temp;

vector<string> mainstring;
vector<int> LCS;
string X, Y;

void permute(string a, int l, int r)
{
    int flag=1;
	if (l == r)
    {
        for (int i = 0; i < mainstring.size(); i++)
        {
            temp = mainstring[i];
            if(temp.compare(a) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            mainstring.push_back(a);
        }
    }

	else
	{
		for (int i = l; i <= r; i++)
		{
			swap(a[l], a[i]);

			permute(a, l+1, r);

			swap(a[l], a[i]);
		}
	}
}

int lcs(int i, int j, int count)
{

    if (i == 0 || j == 0)
        return count;

    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}

void lcs_string()
{
    int i,j,k=0;
    for (i = 0; i < mainstring.size(); i++)
    {
        X = mainstring[i];
        for(j=i+1; j<mainstring.size(); j++)
        {
            Y = mainstring[j];
            k = lcs(X.size(), Y.size(), 0);
            //cout << X << " " << Y << " " << k << endl;
            LCS.push_back(k);


        }
    }
}



int main()
{
	//string str = "0111";
	string str;
	cout<<"enter the binery number: "<<endl;
    cin>>str;
	int n = str.size();
	int i;
	permute(str, 0, n-1);
	/*for (i = 0; i < mainstring.size(); i++)
        cout << mainstring[i] << " ";
    cout << "\n";*/
    lcs_string();
    cout << "The smallest LCS will be " << *min_element(LCS.begin(), LCS.end()) << " char long.";
	return 0;
}

