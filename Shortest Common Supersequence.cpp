/*
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
Example 2

Input:
X = efgh, Y = jghi
Output: 6
Explanation: Shortest Common Supersequence
would be ejfghi which is of length 6 and
has both the strings as its subsequences.
Your Task:
Complete shortestCommonSupersequence() function that takes X, Y, m, and n as arguments and returns the length of the required string.

Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1<= |X|, |Y| <= 100
*/

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(char* x, char* y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i<dp.size();i++)
        {
            for(int j = 1;j<dp[0].size();j++)
            {
                if(x[i-1]==y[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int l = dp[m][n];
        int ans = l;
        ans = ans + m-l;
        ans = ans + n-l;
        return ans;
    }
};
