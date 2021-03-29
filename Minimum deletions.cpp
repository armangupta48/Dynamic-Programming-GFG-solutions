Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: S = "aebcbda"
Output: 2
Explanation: Remove characters 'e' 
and 'd'.
â€‹Example 2:

Input: S = "geeksforgeeks"
Output: 8
Explanation: One of the possible result
string can be "eefee", so answer is 
13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 103



int minimumNumberOfDeletions(string s) { 
    // code here
    vector<vector<int>> dp(s.size(),vector<int>(s.size()));
    for(int g = 0;g<s.size();g++)
    {
        for(int i = 0,j=g;j<s.size();i++,j++)
        {
            if(g==0)
            {
                dp[i][j]=1;
            }
            else if(g==1)
            {
                if(s[i]==s[j])
                dp[i][j] = 2;
                else
                dp[i][j]=1;
            }
            else
            {
                if(s[i]==s[j])
                {
                    dp[i][j] = 2+dp[i+1][j-1];
                }
                else
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return s.size()-dp[0][s.size()-1];
} 
