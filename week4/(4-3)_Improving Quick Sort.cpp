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
    //Problem: Improving Quick Sort
    //
    //Why improving!
    //worst case1 ==> if the pivot (that is first element) is the minimum element of the array
    //its solution => generate a random index between start and end of the array or sub array
    //                and swap with with the first element ==> T(n) = T(n-1)+n = O(n^2)
    //
    //worst case2 ==> if all elements are equal in the array or the sub array
    //its solution => divide the array to 3 parts ==> |  x<  |  x=  | <x  | and ignore the equal
    //                part that range (m1:m2) from the next recursion of the subproblem    //

    //Max n size will be 10^5 ==> int
    //Max inputs size ai size will be 10^9 ==> int (-2^31:2^31-1)
    //Average of This Algorithm T(n) = 2T(n/2)+n = O(nlog(n)) instead of the worst case O(n^2)
//////////////////////////////////////////////////////////////////////////////////////////////

vector<pair<int,int>> partition3(vector<int> &a, int s, int e)
{
    vector<pair<int,int>>m(1);
    int n = e-s+1;
    srand(time(0));
    int i = s+(rand()%n);
    swap(a[s], a[i]);
    int pivot = a[s];
    int j=s,k=s;
    for (int i = s + 1; i <= e; i++)
        {
            if(pivot==a[i])
            {
                k++;
                swap(a[i], a[k]);

            }

            if(pivot>a[i])
            {
                k++;
                swap(a[i], a[k]);
                j++;
                swap(a[k], a[j]);

            }
        }
    swap(a[s], a[j]);
    m[0].first = j;
    m[0].second = k;
    return m;
}

void randomized_quick_sort(vector<int> &a, int s, int e) {
    if (s >= e)
        return;
    /*srand(time(0));
    int n = e-s+1;
    int i = s+(rand()%e);
    swap(a[s], a[i]);*/

    vector<pair<int,int>> m = partition3(a, s, e);
    int m1 = m[0].first;
    int m2 = m[0].second;

    randomized_quick_sort(a, s, m1 - 1);
    randomized_quick_sort(a, m2 + 1, e);
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    randomized_quick_sort(v,0,n-1);
    for(int i=0;i<n;i++)
        cout<<v[i]<<' ';
    cout<<'\n';

}


