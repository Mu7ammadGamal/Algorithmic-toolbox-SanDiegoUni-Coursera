#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<int> coll_sign(vector<pair<int,int>>&a,int n)
{

    //////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: select most end points that is covered by n segments
    //pre-required: sorted vector (asscending end points sort)
    //Max n size will be 10^3 ==> int
    //Max return size will be 10^5*10^5*10^3 = 10^13 ==> long long int (-2^63:2^63-1)
    //This Algorithm O(n) = n , Sort Algorithm O(n) = nlog(n)  ==> total = n + nlog(n)
                                   // O(n) = nlog(n) //
    //////////////////////////////////////////////////////////////////////////////////////////////

    sort(a.begin(),a.end());


    vector<int> res;
    int curr = 0;
    int x=a[curr].second;
    for(int i=1;i<n;i++)
    {
        //cout<<a[curr].first<<" : "<<a[curr].second<<endl;
        //cout<<a[i].first<<" : "<<a[i].second<<endl;
        if(a[i].first>=a[curr].first && a[i].first<=a[curr].second && a[i].first<=x)
        {
            x=min(x,a[i].second);
            //cout<<"True"<<endl;
        }

        else
        {
            curr=i;
            res.push_back(x);
            x=a[curr].second;
            //cout<<"False"<<endl;

        }
        //cout<<x<<endl;
    }
    res.push_back(x);
    return res;


}


int main()
{
    int n,i;
    cin>>n;
    vector<pair<int,int>> pairs(n);
    for(i=0;i<n;i++)
    {
        cin>>pairs[i].first;
        cin>>pairs[i].second;
    }
     vector<int> res = coll_sign(pairs,n);
     cout<<res.size()<<'\n';
     for(auto k : res)
        cout<<k<<' ';

}
