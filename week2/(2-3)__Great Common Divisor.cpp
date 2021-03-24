#include<iostream>
using namespace std;

long long GCD(long long x,long long y)
{
        /** T(n)= log2(n) **/
        /** O(n)= log2(n) **/

        //Base case
        if(y==0)
            return x;

        //Recursive case
        else
            return GCD(y,x%y);
}

main()
{
long long x,y;
cin>>x>>y;
cout<<GCD(x,y)<<endl;
}

