/* 
Geek wants to inspect the quality of vegetables at each shop in the vegetable market. There are N different vegetable sellers in a line. A single kilogram each of brinjal, carrot and tomato are available with every seller but at different prices. Geek wants to buy exactly one vegetable from one shop and avoid buying the same vegetables from adjacent shops. 
Given the cost of each vegetable in each shop in a Nx3 matrix, calculate the minimum amount of money that Geek must spend in the inspection. 


Example 1:

Input: 
N = 3
cost = {{1, 50, 50}, 
        {50, 50, 50}, 
        {1, 50, 50}}
Output: 52
Explaination: 
Shop 1: Buy Brinjals for Rs 1.
Shop 2: Buy Carrot or Tomatoes for Rs 50.
Shop 3: Buy Brinjals for Rs 1.
Total = 1+50+1 = 52

Your Task:
You do not need to read input or print anything. Your task is to complete the function minCost() which takes N and Nx3 matrix cost[][] as input parameters and returns he minimum amount of money that Geek must spend in the inspection. 


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105 
1 ≤ cost[i][j] ≤ 100 */

class Solution{
public:
    int minCost(int n, vector<int> cost[]) {
        // code here
        vector<vector<int>> dp(n,vector<int>(3));
        for(int i = n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                dp[i][0]=cost[i][0];
                dp[i][1]=cost[i][1];
                dp[i][2]=cost[i][2];
            }
            else
            {
                dp[i][0] = cost[i][0]+min(dp[i+1][1],dp[i+1][2]);
                dp[i][1] = cost[i][1]+min(dp[i+1][0],dp[i+1][2]);
                dp[i][2] = cost[i][2]+min(dp[i+1][0],dp[i+1][1]);
            }
        }
        return min(dp[0][0],min(dp[0][1],dp[0][2]));
    }
};
