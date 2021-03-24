#include<iostream>
#include<string>
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
typedef unsigned int u;

//////////////////////////////////////////////////////////////////////////////////////////////
    //Problem: binary search
    //pre-required: sorted vector by user (ascending)
    //Max n,k size will be 10^5 ==> int
    //Max inputs size ai,bi size will be 10^9 ==> int (-2^31:2^31-1)
    //This Algorithm T(n) = 2T(n/2)+n = O(nlog(n))
//////////////////////////////////////////////////////////////////////////////////////////////

int bin_search(vector<int>&a,int start,int end,int key)
{
    //Base Case
    if (start>end)
        return -1;

    //Recursive Case
    int m = (start+end)/2;
    if(key==a[m])
        return m;
    else if(key>a[m])
        return bin_search(a,m+1,end,key);
    else
       return bin_search(a,start,m-1,key);
}

/*int findIndex(vector<int>&v,int key)
{
    auto it = find(v.begin(),v.end(),key);
    return it==v.end()?-1:it-v.begin();
}*/

int main()
{
    int n,k,i=0;
    cin>>n;
    vector<int>v(n);

    for(i=0;i<n;i++)
        cin>>v[i];

    cin>>k;
    vector<int> keys(k);

    for(i=0;i<k;i++)
        cin>>keys[i];

    for(i=0;i<k;i++)
    {
        cout<<bin_search(v,0,n-1,keys[i])<<' ';
        //cout<<findIndex(v,keys[i])<<'\n';
    }

}


