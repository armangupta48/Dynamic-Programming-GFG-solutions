Given a N x N matrix such that each of its cells contains some coins. Count the number of ways to collect exactly K coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

Example 1:

Input:
K = 12, N = 3
arr[] = [[1, 2, 3], 
         [4, 6, 5], 
         [3, 2, 1]]
Output: 2
Explanation: 
There are 2 possible paths 
with exactly K coins, (1 + 4 + 
3 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
Example 2:

Input:
K = 16, N = 3
arr[] = [[1, 2, 3], 
         [4, 6, 5], 
         [9, 8, 7]]
Output: 0 
Explanation: 
There are no possible paths that lead 
to sum=16
Your Task:  
You don't need to read input or print anything. Your task is to complete the function numberOfPath() which takes N, K and 2D matrix arr[][] as input parameters and returns the number of possible paths.

Expected Time Complexity: O(n*n*k)
Expected Auxiliary Space: O(n*n*k)

Constraints:

1 <= K <= 200
1 <= N <= 200
1 <= arrij <= 200

class Solution {
public:
    long long dp[101][101][101];
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        memset(dp, -1, sizeof dp);
        return helper(arr,n-1,n-1,k);
    }
    long long helper(vector<vector<int>>& mat,int m,int n,int k)
    {
        if(k<0)
            return 0;
        if(m<0 || n<0)
        {
            return 0;
        }
        if(m==0 and n==0) return dp[n][m][k]=(k==mat[n][m]);
        if (dp[m][n][k] != -1) return dp[m][n][k];
        dp[m][n][k] = helper(mat, m-1, n, k-mat[m][n]) +
                 helper(mat, m, n-1, k-mat[m][n]);
  
        return dp[m][n][k];
    }
};
