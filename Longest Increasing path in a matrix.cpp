Given a matrix with n rows and m columns. Your task is to find the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You are not allowed to move diagonally or move outside the boundary.


Example 1:

Input:
n = 3, m = 3
matrix[][] = {{1 2 3},
              {4 5 6},
              {7 8 9}}
Output: 
5
Explanation: 
The longest increasing path is 
{1, 2, 3, 6, 9}. 
Example 2:

Input:
n = 3, m = 3
matrix[][] = {{3 4 5},
              {6 2 6},
              {2 2 1}}
Output: 
4
Explanation:
The longest increasing path is
{3, 4, 5, 6}.

Your Task:
You only need to implement the given function longestIncreasingPath() which takes the two integers n and m and the matrix matrix as input parameters, and returns the length of the longest increasing path in matrix.


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)


Constraints:
1 ≤ n,m ≤ 2000
0 ≤ matrix[i] ≤ 230
  
  class Solution {
  public:
  int N,M;
  vector<vector<int>> dp;
  int xx[4] = {1,-1,0,0};
    int yy[4] = {0,0,1,-1};
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {
        N = n;
        M = m;
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        int res= 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                helper(matrix,i,j,1);
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
    int helper(vector<vector<int>>& matrix,int x,int y,int cnt)
    {
        if(dp[x][y]!=-1) return dp[x][y];
        int res = INT_MIN;
        for(int i=0;i<4;i++)
        {
            int tx = x + xx[i];
            int ty = y + yy[i];
            if(tx>=0 && ty>=0 && tx<N && ty<M && matrix[tx][ty]>matrix[x][y])
                res = max(res,1+helper(matrix,tx,ty,cnt+1));
        }
        return dp[x][y] = max(res,1);
        
    }
};
