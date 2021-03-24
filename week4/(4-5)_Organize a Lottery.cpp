#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<iterator>
#include<ctime>
#include<sstream>

using namespace std;
typedef long long ll;
typedef struct Node{int val;int index;int counter;}node;

//////////////////////////////////////////////////////////////////////////////////////////////
    // Problem: Number of segments that cover some numbers
    // Inversion pairs of {9,2,7,3,5} ==> (9,2)(9,7)(9,3)(9,5)(7,3)(7,5) == 6 pairs
    //
    // Idea!
    // divide segments to just 2 numbers: start and end then sort them with the numbers in ascending
    // sort and loop on that vector u sorted then check if the start
    //
    //
    //
    // pre-required: using mapping to store the counter in its value for each point considering it as
    //               as a key ==> (key,value)==(point,counter) cuz after sorting the points vector
    //               u will not be able to put counter  of each point in its order
    //               and the output needs each counter vs its point
    //
    //Max s,p size will be 5*10^4  ==> int
    //Max inputs size Start,End,Xp size will be -10^8:10^8 ==> int (-2^31:2^31-1)
    //This Algorithm T(n) = O(nlog(n))+ O(n) = O(nlog(n))
//////////////////////////////////////////////////////////////////////////////////////////////

void counting(pair<int,int>&s,vector<int>&p,map<int,int>&m){
    int n = p.size();
    vector<int>v(n);
    for(int i=0;i<n;i++)
        v[i]=p[i];
    sort(p.begin(),p.end());
    int res=0;
    for(int i=0,j=0;i<n;i++)
    {
        if (p[i]>=s.first && p[i]<=s.second)
            m[p[i]]++;
    }

}


void count_segments(vector<pair<int,int>>&s,vector<int>&p,map<int,int>&m)
{
    for(int i=0;i<s.size();i++)
    {
        counting(s[i],p,m);
    }
}



int main()
{
    int s,p;
    cin>>s>>p;

    vector<pair<int,int>> seg(s);  //pair<int start,int end>
    for(int i=0;i<s;i++)
    {
        cin>>seg[i].first>>seg[i].second;
    }

    vector<int> vpoints(p);
    map<int,int> mpoints; //map<key,value>
    for(int i=0;i<p;i++)
    {
        cin>>vpoints[i];
        mpoints.insert({vpoints[i],0});
    }

    count_segments(seg,vpoints,mpoints);
    for(int i=0;i<p;i++)
        cout<<mpoints[vpoints[i]]<<' ';
}


