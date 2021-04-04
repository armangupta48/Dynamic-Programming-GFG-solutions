// it is sma e like a coin change problem we have to find combination not permutions(distinct ways)
/*There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).

Note:
Order does not matter means for n = 4 {1 2 1},{2 1 1},{1 1 2} are considered same.
 

Example 1:

Input: N = 4
Output: 3
Explanation: Three ways to reach at 4th stair.
They are {1, 1, 1, 1}, {1, 1, 2}, {2, 2}.
Example 2:

Input: N = 5
Output: 3
Explanation: Three ways to reach at 5th stair.
They are {1, 1, 1, 1, 1}, {1, 1, 2, 1} and
{1, 2, 2}.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function nthStair() which takes N as input parameter and returns the total number of ways to reach at Nth stair.
 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1 <= N <= 1000000*/

class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    vector<int>dp(n+1,0);
		    int a[2] = {1,2};
		    dp[0]=1;
		    for(int i = 0;i<2;i++)
		    {
		        int curr = a[i];
		        for(int j = curr;j<=n;j++)
		        {
		            dp[j] = dp[j]+dp[j-curr];
		        }
		    }
		    return dp[n];
		}
};
