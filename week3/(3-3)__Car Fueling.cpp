#include<iostream>
#include<vector>
using namespace std;


int min_refill(vector<int>&v,int n,int m,int d)
{
    /** O(n) = n **/
    if(d-v[n-2]>m)
        return -1;

    int curr=0,num=0,last=0;
    while(curr<=n-2)
    {
        if(m>=v[curr+1]-v[last])
            curr++;
        else
        {
            if(curr == last)
                return -1;
            if(curr<=n-2)
                num++;
            last = curr;

        }
    }
    return num;
}

int main()
{
    int d,m,n;
    cin>>d>>m>>n;
    n+=2;
    vector<int> v(n);
    v[0]=0;
    for(int i=1;i<n-1;i++)
    {
        cin>>v[i];
    }
    v[n-1]=d;
    cout<<min_refill(v,n,m,d)<<endl;
}
