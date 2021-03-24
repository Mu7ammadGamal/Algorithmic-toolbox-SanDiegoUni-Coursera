#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<iterator>
#include<ctime>
#include<sstream>

using namespace std;
typedef long long ll;


string max_salary(vector<int>&v,int n)
{
    //////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: sorting some papers has numbers to get max salary (sorting some numbers descending)
    //pre-required: divide each digit if the number is >10  ==> 125 -> 1 2 5
    //Max n size will be 10^2 ==> int
    //Max input number will be 10^3 ==> 4 digit
    //Max result will be (input digits * 100) 4 digit * 100 = 400 digits ==> String is better (no range enough for 400 digit LOL)
    //Converting Algorithm O(n) = n^(2) , Sort Algorithm O(n) = nlog(n)  ==> total = n + nlog(n)
    // This Algorithm ==> n^(2)
    //////////////////////////////////////////////////////////////////////////////////////////////


    //Descending Sort by Selection
    int maxDigit;
    for(int i = 0;i<n;i++)
    {
        maxDigit = i;
        for(int j = i+1;j<n;j++)
        {
            if(v[j]> v[maxDigit])
               {
                    maxDigit = j;
               }
        }
        swap(v[maxDigit],v[i]);
    }

    string str;
    //convert from int to string (to concatenate)
    for(int i=0;i<n;i++)
    {
        stringstream ss;
        ss<<v[i];
        string temp;
        ss>>temp;
        str+=temp;
    }

    return str;

}

string max_salary2(vector<int>&v,int n)
{
    //Converting Algorithm O(n) = n , Sort Algorithm O(n) = nlog(n)  ==> total = n + nlog(n)
    // This Algorithm ==> nlog(n)
    sort(v.rbegin(),v.rend());
    string str;
    //convert from int to string (to concatenate)
    for(int i=0;i<n;i++)
    {
        stringstream ss;
        ss<<v[i];
        string temp;
        ss>>temp;
        str+=temp;
    }
    return str;
}



int main()
{
    int n;
    cin>>n;
    vector<int> digits(n);
    for(int i=0;i<n;i++)
        cin>>digits[i];
    cout<<max_salary(digits,n)<<'\n';
    //cout<<max_salary2(digits,n)<<'\n';


    /*//Stress Testing
    string digits;
    srand(time(0));
    int n = 0+rand()%100; // generate rand number in range 1:100
    while(true)
    {
        for(int i =0;i<n;i++)
            {
                stringstream ss;
                string s;
                ss<<999+rand()%1000;
                ss>>s;
                digits+=s;        //fill the vector by random number in range 1:100



                cout<<max_salary(digits,n)<<'\n';
                cout<<max_salary2(digits,n)<<'\n';
                cout<<max_salary3(digits,n)<<'\n';
            }
    }*/

}


