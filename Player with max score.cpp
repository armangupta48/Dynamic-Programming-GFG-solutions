/*
Given an array arr of non-negative integers of size N, 2 players are playing a game. In each move, a player chooses an element from either end of the array, and the size of the array shrinks by one. Both players take alternate chances and the game continues until the size of the array becomes 0. Every time a player chooses an array element the array value is added to the player's score. At the need player with maximum score wins.
You have to predict whether player 1 will win the game or not. Both players will play optimally.
 

Example 1:

Input:
N = 3
arr[] = {2,6,3}
Output:
0 
Explanation:
Initially, player 1 can choose between 2 and 3. 
If he chooses 3 (or 2), then player 2 can choose 
from 2 (or 3) and 6. If player 2 chooses 6,
then player 1 will be left with 2 (or 3). 
So, final score of player 1 is 2 + 3 = 5,
and player 2 is 6. 
Hence, player 1 will never be the winner and 
output is 0.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function is1winner() which takes the array arr[], its size N and returns true if player 1 is the winner and false otherwise.
The driver code itself prints 1 if returned value is true and 0 otherwise.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)


Constraints:
1 <= N <= 1000
0<= arr[i] <= 105
*/

class Solution{   
public:
    bool is1winner(int n,int nums[]) {
        
        // code here
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum = sum+nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(n));
        for(int g = 0;g<n;g++)
        {
            for(int i = 0,j=g;j<n;i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=nums[i];
                }
                else if(g == 1)
                {
                    dp[i][j] = max(nums[i],nums[j]);
                }
                else
                {
                    int a = nums[i]+min(dp[i+1][j-1],dp[i+2][j]);
                    int b = nums[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j] = max(a,b);
                }
            }
        }
        return dp[0][n-1]>=sum-dp[0][n-1];
    }
};
