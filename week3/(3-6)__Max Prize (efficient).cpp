#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;

string max_prize(ll n)
{


    //////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: find number counter with no repeat
    //Max n size will be 10^9 ==> long long int
    //Max return size will be 10^5*10^5*10^3 = 10^13 ==> long long int (-2^63:2^63-1) or string better
    //This Algorithm O(n) = n , Sort Algorithm O(n) = nlog(n)  ==> total = n + nlog(n)
                                   //  O(n) = nlog(n)
    //////////////////////////////////////////////////////////////////////////////////////////////

    ll i=1,sum=0;
    int num_size=0;
    string num;
    while(1)
    {
      sum+=i;
      ++num_size;
      stringstream ss;
      string temp;
      if(n<3) //case of n = 1, 2
      {
          ss<<n;
          ss>>temp;
          num+=temp+' ';
          break;
      }
      else if(n-sum<=i) //case of repeating number will appear
      {
          ss<<n-(sum-i);//sum - i cuz it += before if statements
          ss>>temp;
          num+=temp+' ';
          break;
      }
      else // normal case 1,2,3,4,4 .... case of repeating number will appear
      {
          ss<<i;
          ss>>temp;
          num+=temp+' ';
      }

      i++;
    }
    cout<<num_size<<'\n';
    return num;
}

string max_prize2(ll n)
{
    // try this algorithm on calculator
    // if n =8
    // 8-1=7     7>1 ==> True  ==> num = 1
    // 7-2=5     5>2 ==> True  ==> num = 1,2
    // 5-3=2     2>3 ==> False ==> num = 1,2,last n ==> 1,2,5

    ll i=1;
    string num;
    while(1)
    {
      stringstream ss;
      string temp;
      if(n-i>i) // normal case 1,2,3,4,5 .... case of non repeating number will appear
      {
          n-=i;
          ss<<i;
          ss>>temp;
          num+=temp+' ';
      }
      else //case of repeating number will appear (it will be < current i)
      {
          ss<<n;
          ss>>temp;
          num+=temp+' ';
          break;
      }
      i++;
    }
    return num;
}


int main()
{
    ll n;
    cin>>n;
    string str = max_prize2(n);
    cout<<str.length()/2<<'\n';
    cout<<str<<'\n';

}


