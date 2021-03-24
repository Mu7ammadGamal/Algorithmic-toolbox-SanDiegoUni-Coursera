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
                res[i][j]=((res[i][j]+mat1[i][k]*mat2[k][j]))%10;

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

short fib_more_efficient(llu n)
{
        /** O(n) = log(n) **/

    /*
    fib_mat = | 1  1 | = | f(2)  f(1) |
              | 1  0 |   | f(1)  f(0) |


    (fib_mat)^(n-1) = | f(n)    f(n-1) |^(n-1)
                      | f(n-1)  f(n-2) |

    f(n)   = (fib_mat)^(n-1)[0][0]
    f(n-1) = (fib_mat)^(n-1)[0][1] = (fib_mat)^(n-1)[1][0]
    f(n-2) = (fib_mat)^(n-1)[1][1]
    */
        if(n<2)
            return n;

        short fib_mat[2][2]={{1,1},{1,0}};
        pow_efficient(fib_mat,n-1);

        return (fib_mat[0][0])%10;
}

short fib_more_efficient_sumOfSquares(llu n)
{
    //Mathematically proof Sum of F(n)^(2) = F(n)*F(n+1)
    return (fib_more_efficient(n)*fib_more_efficient(n+1))%10;
}



main()
{
unsigned long long n;
scanf("%llu",&n);
printf("%hu",fib_more_efficient_sumOfSquares(n));
}
