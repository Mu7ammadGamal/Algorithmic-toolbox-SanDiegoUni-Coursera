#include<iostream>
using namespace std;
typedef long long unsigned llu;

//Matrix Exponential Algorithm
void matrix_mul(short mat1[2][2],short mat2[2][2])
{
    short res[2][2]={0};
    for(int i = 0;i<2;i++)
        for(int j = 0;j<2;j++)
            for(int k = 0;k<2;k++)
                res[i][j]=(res[i][j]+mat1[i][k]*mat2[k][j])%10;

    for(int i = 0;i<2;i++)
        for(int j = 0;j<2;j++)
            mat1[i][j] = res[i][j];
}

void pow_efficient(short mat[2][2],llu n)
{
    /** O(n) = log(n) **/
    //Base Cases
    if(n==1)
        return;

    //Recursive Case
    short mat_temp[2][2]={{1,1},{1,0}};
                                        //if n=5 --> A^5  = (A^2)^2 . A
    pow_efficient(mat,n/2);             //pow_naive(A,5/2 = 2) so, p = (A^2)
    matrix_mul(mat,mat);                //  p = (A^2)*(A^2) = (A^2)^2

    if(n%2==1)                          // odd check -->  n = 5 so, 5%2 = 1  --> remain 1 A
        matrix_mul(mat,mat_temp);       //p = (A^2)^2 . A = A^5 #######
    return;

}

short fib_more_efficient_LastDigit(llu n)
{
        /** O(n) = log(n) **/
        if(!n)
            return 0;
        if(n==1 || n==2)
            return 1;

        short fib_mat[2][2]={{1,1},{1,0}};
        pow_efficient(fib_mat,n-1);
        return fib_mat[0][0];
}

short fib_more_efficient_sumOfLastDigits(llu n)
{
        /** O(n) = log(n) **/
        if(n<3)
            return n;

        short fib_mat[2][2]={{1,1},{1,0}};
        pow_efficient(fib_mat,n-1);
        return (fib_mat[0][0]+fib_mat[0][1]+fib_mat[1][0]+fib_mat[1][1]-1)%10;
}

short fibonacci_sumOfLastDigit_nTOm(llu n,llu m)
{
    // 0:7  F0+F1+F2+F3+F4+F5+F6+F7
    // 0:3  F0+F1+F2+F3
    // 0:2  F0+F1+F2
    // F3 to F7 = F3+F4+F5+F6+F7 = F7-F2
    if(n==m)
        return fib_more_efficient_LastDigit(n);
    if(n<2)
        return fib_more_efficient_sumOfLastDigits(m)%10;

    return (10+fib_more_efficient_sumOfLastDigits(m)-fib_more_efficient_sumOfLastDigits(n-1))%10;
    // +10 to avoid negative sign and it will not affect on the positive because of the %
    //F4=7  F8=54 --> last digit = 4-7=-3 XX last digit=(54-7)%10=7 = (-3+10)%10 --> thats why we add 10
    //F5=12 F8=54 --> last digit = 4-2=3 VV last digit=(54-12)%10=2 =  (2+10)%10 --> thats why we add 10

}


main()
{
llu n,m;
scanf("%llu %llu",&n,&m);
printf("%hu",fibonacci_sumOfLastDigit_nTOm(n,m));
//printf("%llu",fib_more_efficient(n));
}


