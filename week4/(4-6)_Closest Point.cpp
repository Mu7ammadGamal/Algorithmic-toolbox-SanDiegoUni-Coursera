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
bool compareBy_Y(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second>b.second; //ascending
}
float  point_dist(pair<int,int>&p,pair<int,int>&q)
{
    int x1=p.first;
    int y1=p.second;
    int x2=q.first;
    int y2=q.second;
    return (float)sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
float  strip(vector<pair<int,int>>&v,float  d,int m)
{
    int s=m,e=m;
    int mval = v[m].first;

    for(int i = m+1;i<v.size();i++)
        if(v[i].first-mval<d)
            e=i;

    for(int i = m-1;i>=0;i--)
        if(mval-v[i].first<=d)
            s=i;

    vector<pair<int,int>> stripVec(e-s+1);
    for(int i = s,j=0;i<=e;i++,j++)
    {
        stripVec[j].first = v[i].first;
        stripVec[j].second = v[i].second;
    }
    sort(stripVec.begin(),stripVec.end(),compareBy_Y);

    float  minn = point_dist(v[0],v[1]);
    for(int i=0;i<stripVec.size();i++)
        for(int j=i+1;j-i<=7 && i<stripVec.size() ;j++)
            minn = min(minn,point_dist(v[i],v[j]));
    return minn;

}
float  min_distanceX(vector<pair<int,int>>&v,int s ,int e)
{
    int n = e-s+1;
    if(n==2)
        return point_dist(v[s],v[e]);

    if(n==1)
        return point_dist(v[s-1],v[e]);

    int m = (s+e)/2;
    float  A = min_distanceX(v,s ,m);
    float  B = min_distanceX(v,m+1,e);
    float  d = min(A,B);
    return d;

}

float  min_distance(vector<pair<int,int>>&v,int s ,int e)
{
    sort(v.begin(),v.end());
    float  d = min_distanceX(v,s ,e);
    float  dd = strip(v,d,(s+e)/2);
    float  D = min(d,dd);
    return D;
}


int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
        cin>>v[i].second;
    }
    printf("%0.4f",min_distance(v,0,n-1));



}


