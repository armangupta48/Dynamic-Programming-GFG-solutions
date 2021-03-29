Given a string str you have to answer several queries on that string. In each query you will be provided two values L and R and you have to find the number of distinct characters in the sub string from index L to index R (inclusive) of the original string.
 

Example 1:

Input: str = "abcbaed",
Query = {{1,4},{2,4},{1,7}}
Output: {3,2,5}
Explanation: For the first query distinct 
characters from [1, 4] are a, b and c.
For the second query distinct characters from
[2, 4] are b and c.
For the third query distinct characters from
[1, 7] are a, b, c, d and e.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function SolveQueries() which takes str and Query as input parameter and returns a list containing answer for each query.
 

Expected Time Complexity: O(max(length of str, 26 * No of queries))
Expected Space Complexity: O(26 * length of str)
 

Constraints:
1 <= |str| <= 105
1 <= No of Queries <= 104
1 <= Li <= Ri <= |str|
  
  
  
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    // Code here
	    vector<vector<int>> dp(str.size(),vector<int>(26,0));
	    for(int i =0;i<str.size();i++)
	    {
	        if(i==0)
	        {
	            dp[i][str[i]-'a']=1;
	        }
	        else
	        {
	            for(int j = 0;j<26;j++) dp[i][j] = dp[i-1][j];
	            dp[i][str[i]-'a']++;
	        }
	    }
	    vector<int> res;
	    for(auto a : Query)
	    {
	        int l = a[0];
	        int r = a[1];
	        l--;
	        r--;
	        int cnt =0;
	        for(int i = 0;i<26;i++)
	        {
	            if(l==0)
	            {
	                if(l == 0)cnt += (dp[r][i] > 0);
	            }
	            else
	            {
	                cnt += (dp[r][i]-dp[l-1][i] >0);
	            }
	        }
	        res.push_back(cnt);
	    }
	    return res;
	}
};
