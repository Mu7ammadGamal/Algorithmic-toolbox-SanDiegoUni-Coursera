#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
typedef long long unsigned llu;
typedef long double ld;
struct items{ld vw;int w;};

////////////// lesson of today /////////////////
//compare functor to sort vw descending       //
bool compareBy_vw(const items&a,const items&b)//
{                                             //
    return a.vw>b.vw;                         //
}                                             //
////////////////////////////////////////////////

ld max_loot(vector<items>&vec,int n,int W)
{

    int q;
    ld V=0; //Max Value of the W
    for(int i=0;i<n && W>0;i++)
    {
         q=min(vec[i].w,W);
         V+=q*vec[i].vw;
         W-=q;
    }
    return V;
}

int main()
{
    int n,v,W;
    cin>>n>>W;
    vector<items> vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>v>>vec[i].w;
        vec[i].vw=(ld)v/vec[i].w;
    }
    sort(vec.begin(),vec.end(),compareBy_vw);
    printf("%0.4Lf",max_loot(vec,n,W));



}
