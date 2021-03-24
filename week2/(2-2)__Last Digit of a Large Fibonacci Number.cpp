#include<iostream>
#include<cmath>
using namespace std;



// to find last digit of any number use X%10
// x = 45 last_digit = 45%10 = 5

int fibonacci_last_digit(int n)
{
        /** T(n)= 2n+2 **/
        /** O(n)= n **/
        if(!n)
            return 0;

        int x=0,y=1,temp=1;
        for(int i = 2;i<=n;i++)
        {
            temp = (x+y)%10;
            x=y;
            y=temp;
        }
        return temp;// to get last digit

}

main()
{
int n;
cin>>n;
cout<<fibonacci_last_digit(n)<<endl;
}
