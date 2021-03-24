#include<iostream>
using namespace std;

long long fibonacci(int n)
{
        /** T(n)=2n+2 **/
        if(!n)
            return n;

        long long x=0,y=1,temp=1;
        for(int i = 2;i<=n;i++)
        {
            temp = x+y;
            x=y;
            y=temp;
        }
        return temp;
}

main()
{
int n;
cin>>n;
cout<<fibonacci(n)<<endl;
}
