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


string max_salary(string&str,int n)
{
    //////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: sorting some papers has numbers to get max salary (sorting some numbers descending)
    //pre-required: divide each digit if the number is >10  ==> 125 -> 1 2 5
    //Max n size will be 10^2 ==> int
    //Max input number will be 10^3 ==> 4 digit
    //Max result will be (input digits * 100) 4 digit * 100 = 400 digits ==> String is better (no range enough for 400 digit LOL)
    //This Algorithm O(n) = n , Sort Algorithm O(n) = nlog(n)  ==> total = n + nlog(n)
                                   //  O(n) = nlog(n)
    //////////////////////////////////////////////////////////////////////////////////////////////


    string res;
    for(int i = 0;i<str.length();i++)
    {
        if(str[i]!=' ')
            res+=str[i];
    }
    n = res.length();


    //Descending Sort by Selection
    int maxDigit;
    for(int i = 0;i<n;i++)
    {
        maxDigit = i;
        for(int j = i+1;j<n;j++)
        {
            if(res[j]> res[maxDigit])
               {
                    maxDigit = j;
               }
        }
        swap(res[maxDigit],res[i]);
    }

    return res;

}

string max_salary2(string&str,int n)
{
    string res;
    for(int i = 0;i<str.length();i++)
    {
        if(str[i]!=' ')
            res+=str[i];
    }
    sort(res.rbegin(),res.rend());
    return res;
}

string max_salary3(string&str,int n)
{
str.erase(remove(str.begin(),str.end(),' '),str.end());
sort(str.rbegin(),str.rend());
return str;
}



int main()
{
    int n;
    cin>>n;
    string digits;
    cin.ignore();
    getline(cin,digits);
    cout<<max_salary(digits,n)<<'\n';
    //cout<<max_salary2(digits,n)<<'\n';
    //cout<<max_salary3(digits,n)<<'\n';


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


