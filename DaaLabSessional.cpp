#include <limits.h>
#include <stdio.h>
 
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
void MatrixChainOrder(int p[], int n)
{
    int dp[n][n];
    int par[n][n];
 
    int i, j, k, L, q;
 
    /* m[i, j] = Minimum number of
       scalar multiplications
       needed to compute the matrix*/
 
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++)
        dp[i][i] = 0;
 
    // L is chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications
                q = dp[i][k] + dp[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j])
                {
                    dp[i][j] = q;
                    par[i][j] = k;//i<=k<j
                }    
            }
        }
    }
 printf("\nOPTIMAL COST IS AS FOLLOWS :---\n");
 for(int i = 0;i<n;i++)
 {
     for(int j = 0;j<n;j++)
     {
         if((i==1&&j==5)||(i==2&&j==4)||(i==1&&j==3))
            printf("C[%d][%d] = %d\n",i,j,dp[i][j]);
     }
 }
 
 printf("\nPARTITION COST(i,j) IS AS FOLLOWS :---\n");
 for(int i = 0;i<n;i++)
 {
     for(int j = 0;j<n;j++)
     {
         if((i==1&&j==5)||(i==2&&j==4)||(i==1&&j==3))
            printf("P[%d][%d] = %d\n",i,j,par[i][j]);
     }
 }

}
 
// Driver  code
int main()
{
    int arr[] = { 10, 100, 20, 300, 40, 500};
    int size = sizeof(arr) / sizeof(arr[0]);
    MatrixChainOrder(arr, size);
 
    return 0;
}