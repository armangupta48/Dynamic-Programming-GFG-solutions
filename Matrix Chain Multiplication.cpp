Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications. The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. The efficient way is 
(A*(B*C))*D. The number of operations are 20*30*10 
+ 40*20*10 + 40*10*30 = 26000.

Example 2:

Input: N = 4
arr = {10, 30, 5, 60}
Output: 4500
Explaination: The matrices have dimensions 
10*30, 30*5, 5*60. Say the matrices are A, B 
and C. The most efficient way is (A*B)*C. The 
number of multiplications are 10*30*5 + 10*5*60 
= 4500.

Your Task:
You do not need to take input or print anything. Your task is to complete the function matrixMultiplication() which takes the value N and the array arr[] as input parameters and returns the minimum number of multiplication operations needed to be performed.


Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2)


Constraints: 
2 ≤ N ≤ 100
1 ≤ arr[i] ≤ 500


class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n-1,vector<int>(n-1));
        for(int g= 0;g<dp.size();g++)
        {
            for(int i = 0,j=g;j<dp.size();i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=0;
                }
                else if(g==1)
                {
                    dp[i][j]=arr[i]*arr[j]*arr[j+1];
                }
                else
                {
                    int minv = INT_MAX;
                    for(int k = i;k<j;k++)
                    {
                        int lc = dp[i][k];
                        int rc = dp[k+1][j];
                        int mc = arr[i]*arr[k+1]*arr[j+1];
                        int tc = lc+rc+mc;
                        if(tc<minv)
                        {
                            minv = tc;
                        }
                    }
                    dp[i][j] = minv;
                }
            }
        }
        return dp[0][dp.size()-1];
    }
};
