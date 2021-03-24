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

//////////////////////////////////////////////////////////////////////////////////////////////
    // Problem: Number of Inversion that (ai > aj)
    // Inversion pairs of {9,2,7,3,5} ==> (9,2)(9,7)(9,3)(9,5)(7,3)(7,5) == 6 pairs
    //
    // Idea!
    // if we divided the array {2,7,9,3,5} to 2 sub array (ascending sort) ==> i{2,7,9} j{3,5}
    // logically if an element of array i (Ai) > element in array j (Bj)  so, All remain elements
    // of array i (An-i)are > this element of array j (Bj)
    // for example: 7i > 3j so 9i > 3j too ==> number of pairs = (n-i(7))+(n-i(7)) = 3-1 + 3-1 = 4
    //  cuz j pointer moved twice from 3 to 5 and both are < 7i
    //
    // pre-required: using merge sort to be sure that each subproblem is sorted
    //               and count each return pairs number to get all number of pairs
    //
    //Max n size will be 10^5 ==> int
    //Max inputs size ai size will be 10^9 ==> int (-2^31:2^31-1)
    //Average of This Algorithm T(n) = 2T(n/2)+ O(n) = O(nlog(n))
//////////////////////////////////////////////////////////////////////////////////////////////

//pair<vector<int>,int>
vector<int> merging(vector<int>&b,vector<int>&c,int&pairsNum)
{
    int bsize = b.size();
    int csize = c.size();
    int n = bsize+csize;
    vector<int> res(n);
    int i=0,j=0,k=0;
    while(i<bsize && j<csize)
    {
        if(b[i]<=c[j])
        {
            res[k]=b[i];
            i++;

        }
        else
        {
            res[k]=c[j];
            pairsNum+=(bsize-i);
            j++;
        }
        k++;
    }

    while(i<bsize)
    {
       res[k]=b[i];
       i++;
       k++;
    }
    while(j<csize)
    {
        res[k]=c[j];
        j++;
        k++;
    }
     return res;
}

vector<int> mergeSort(vector<int>&v,int n,int&pairsNum)
{
    if(n==1)
    {
      return v;
    }
    int m = n/2;
    vector<int> a;
    vector<int> b;
    for(int i =0;i<m;i++)
    {
        a.push_back(v[i]);
    }
    for(int i =m;i<n;i++)
    {
        b.push_back(v[i]);
    }
    vector<int> A = mergeSort(a,a.size(),pairsNum);
    vector<int> B = mergeSort(b,b.size(),pairsNum);
    vector<int> V = merging(A,B,pairsNum);
    return V;
}

int inversion(vector<int>&v,int n)
{
    int invPairs = 0;
    mergeSort(v,n,invPairs);
    return invPairs;
}


int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<inversion(v,n)<<'\n';
}



