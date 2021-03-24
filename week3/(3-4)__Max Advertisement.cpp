#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;


ll max_adv(vector<int>&a,vector<int>&b,int n)
{

    //////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: put the highest profit/click at the slot of many clicks
    //pre-required: sorted vectors
    //Max n size will be 10^3 ==> int
    //Max return size will be 10^5*10^5*10^3 = 10^13 ==> long long int (-2^63:2^63-1)
    //This Algorithm O(n) = n , Sort Algorithm O(n) = nlog(n)  ==> total = n + nlog(n)
                                    /** O(n) = nlog(n) **/
    //////////////////////////////////////////////////////////////////////////////////////////////

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    ll v=0;
    for(int i=0;i<n;i++)
    {
        v+=(ll)a[i]*b[i];
    }
    return v;
}


int main()
{
    int n,i;
    cin>>n;
    vector<int> profit_per_click(n);
    vector<int> clicks(n);
    for(i=0;i<n;i++)
    {
        cin>>profit_per_click[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>clicks[i];
    }
    cout<<max_adv(profit_per_click,clicks,n)<<endl;
}
