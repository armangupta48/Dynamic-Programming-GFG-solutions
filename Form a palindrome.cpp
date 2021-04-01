Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd

Example 1:

Input:
abcd
Output:
3
Explanation:
Here we can append 3 characters in the 
beginning,and the resultant string will 
be a palindrome ("dcbabcd").
Example 2:

Input:
aba
Output:
0
Explanation:
Given string is already a pallindrome hence
no insertions are required.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function findMinInsertions() which takes string S as input parameters and returns minimimum numser of insertions required.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 500

--------------------------------------------------------------------------------------
class Solution{   
public:
    int findMinInsertions(string s){
        // code here 
        int n = s.size();
        int l = 0;
        int r = n-1;
        if(l>=r)
            return 0;
        vector<vector<int> > dp(n,vector<int>(n,-1));
        return helper(s,l,r,dp);
    }
    int helper(string& s,int l,int r,vector<vector<int>>& dp)
    {
        if(l>r)
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        if(l==r)
        {
            return dp[l][r] = 0;
        }
        if(s[l]==s[r])
        {
            return dp[l][r]=helper(s,l+1,r-1,dp);
        }
        return dp[l][r] = 1+min(helper(s,l+1,r,dp),helper(s,l,r-1,dp));
    }
};
