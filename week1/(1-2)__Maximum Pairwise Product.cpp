#include <iostream>
#include<cstdlib>
#include <algorithm>
#include <vector>
#include<iterator>
#include<ctime>
using namespace std;

long long maxPairWise(vector<int>v)
{
    //solution 1
    int n = v.size();
    long long res =1;
    for(int i=0;i<2;i++)
    {
        int max_index =0;
        for(int j=0;j<n;j++)
        {
            if(v[j]>v[max_index])
                {max_index = j;}
        }
        swap(v[max_index],v[n-1]);
        res*=(long long)v[n-1];
        n--;
    }
    return res;

    //solution 2
    /*sort(v.begin(),v.end());
    int n = v.size();
    long long res = (long long)v[n-1]*v[n-2];
    return res;*/
}

main()
{
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i =0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<maxPairWise(v)<<endl;
    //stress test
    /*srand(time(0));
    int n = 1+rand()%2; // generate rand number in range 1:10
    vector <int> v(n);
    cout<<n<<endl;
    while(true)
    {
        for(int i =0;i<n;i++)
            {v[i] = 10000000+rand()%1000000000;} //fill the vector by random number in range 1:10
        for(int i =0;i<n;i++)
            {cout<<v[i]<<" ";}
        cout<<"\n";
        cout<<maxPairWise(v)<<endl;
    }*/


}
