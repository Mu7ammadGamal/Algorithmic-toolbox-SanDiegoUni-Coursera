#include<iostream>
using namespace std;

/*
for ex:
    GCD(21,6) = 3
    21--> 1,(3),7,21
    6 --> 1,2,(3),6

    multiples(21,6)
    21--> 21,(42),63,(84),105,(126)
    6 --> 6,12,18,24,30,36,(42),48,54,60,66,72,78,(84),90,96,102,108,114,120,(126)

    LCM = GCM/GCM
        = (21*6)/(3)
        = 42

*/

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
long long LCM(long long x,long long y)
{
    return (x*y)/GCD(x,y);
}


main()
{
long long x,y;
cin>>x>>y;
cout<<LCM(x,y)<<endl;
}

