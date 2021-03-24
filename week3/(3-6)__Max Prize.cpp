#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
typedef long long ll;


vector<ll> max_prize(ll n)
{


    //////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: put the highest profit/click at the slot of many clicks
    //pre-required: sorted vectors
    //Max n size will be 10^9 ==> long long int
    //Max return size will be 10^5*10^5*10^3 = 10^13 ==> long long int (-2^63:2^63-1)
    //This Algorithm O(n) = n , Sort Algorithm O(n) = nlog(n)  ==> total = n + nlog(n)
                                   //  O(n) = nlog(n)
    //////////////////////////////////////////////////////////////////////////////////////////////

    ll i=1,sum=0;
    vector<ll>num;
    while(1)
    {
      sum+=i;
      if(n<3) //case of n = 1, 2
      {
          num.push_back(n);
          break;
      }
      else if(n-sum<=i) //case of repeating number will appear
      {
          num.push_back(n-(sum-i)); //sum - i cuz it += before if statements
          break;
      }
      else // normal case 1,2,3,4,4 .... case of repeating number will appear
      {
          num.push_back(i);
      }

      i++;
    }
    return num;
}


/*void max_prize(int n){

double x = floor((sqrt(8*(double)n+1)-1)/2);
int sum=0;
cout<<x<<"\n";
for(int i=1;i<=x;i++)
{
    if(i==x)
        cout<<n-sum<<" ";
    else
        {
            cout<<i<<" ";
            sum+=i;}
}
}*/

int main()
{
    ll n;
    string str;
    cin>>n;
    vector<ll> summands(n);
    summands = max_prize(n);
    cout << summands.size() << '\n';
    for (short i = 0; i < summands.size(); ++i)
        {
            //cout << summands[i] << ' ';
            stringstream ss;
            ss<<summands[i];
            string temp;
            ss>>temp;
            if(i==summands.size()-1)
                str+=temp;
            else
                str+=temp+' ';


        }
        cout<<str<<endl;

}


