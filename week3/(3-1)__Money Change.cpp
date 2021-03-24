#include<iostream>
#include <algorithm>
using namespace std;


/*int money_change(int m)
{

    // Greedy Algorithm ==> O(n/10) = O(n)
    // 28 = 10 + 10 + while(sum>m) ==>                      m = 28, sum1 = 20, k1 = 2   subproblem1
    //              + 5 + while(sum>m) ==>                  m =  8, sum2 =  5, k2 = 1   subproblem2
    //                  + 1 + 1 + 1 + while(sum>m) ==>      m =  3, sum3 =  3, k3 = 3   subproblem3
    //                                                      ======= exit loop =======
    //                                                      sum = s1 + s2 + s3 = 28
    //                                                      c = k1 + k2 + k3 = 6

    short coins[3]={10,5,1};
    int i=0,k=0,sum=0,c=0;
    while(m)
    {
        sum+=coins[i];
        k++;         // each time it counts appearance of coins[i] in m to += in c ==> total counter
        if(sum>m)    // check if one coins[i] more to subtract it and decrease counter k
        {
            c+=--k;
            m-=(k*coins[i]);
            sum=0;   // =0 to the next iteration
            k=0;     // =0 to the next iteration
            i++;     // to use the next coin in the array
        }
    }
    return c;
}*/
int money_change2(int m)
{

    // Greedy Algorithm ==> O(n/10) = O(n)
    // if m = 28
    // 28 - 10 = 18 ==>  18 >= 10   T
    // 18 - 10 = 8  ==>  8  >= 10   F  ==> break internal loop while(m>=coins[i])
    // 8  - 5  = 3  ==>  3  >= 5    F  ==> break internal loop while(m>=coins[i])
    // 3  - 1  = 2  ==>  2  >= 1    T
    // 2  - 1  = 1  ==>  1  >= 1    T
    // 1  - 1  = 0  ==>  1  >= 1    T
    // --------------->  m  == 0    F  ==> break outer loop while(m)

    short coins[]={10,5,1};
    int i=0,c=0;
    while(m)
    {
        while(m>=coins[i])
        {
           m-=coins[i];
           c++;
        }
        i++;
    }
    return c;
}


/*int money_change_efficient(int m)
{
    // Greedy Algorithm ==> O(1)
    int tens,fives,ones;
    tens = m/10;
    fives = (m-(tens*10))/5;
    ones = m-(tens*10)-(fives*5);
    return tens+fives+ones;
}*/


int main()
{
    int m;
    cin>>m;
    //cout<<money_change_efficient(m)<<endl;
    //cout<<money_change(m)<<endl;
    cout<<money_change2(m)<<endl;

}
