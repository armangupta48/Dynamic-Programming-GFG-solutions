Given a String S, Find all possible Palindromic partitions of the given String.
 

Example 1:

Input:
S = "geeks"
Output:
g e e k s
g ee k s
Explanation:
All possible palindromic partitions
are printed.
Example 2:

Input:
S = "madam"
Output:
m a d a m
m ada m
madam

Your Task:
You don't need to read input or print anything. Your task is to complete the function allPalindromicPerms() which takes a String S as input parameter and returns a list of lists denoting all the possible palindromic partitions.

 

Expected Time Complexity: O(N*2N)
Expected Auxiliary Space: O(N2), where N is the length of the String

 

Constraints:
1 <= |S| <= 20
  
  
  class Solution {
  public:
    vector<vector<string>> getGray(string s) {
        // code here
        vector<string> curr;
        vector<vector<string>> res;
        helper(res,curr,s,0);
        return res;
    }
    void helper(vector<vector<string>>&res,vector<string>& curr,string &s,int i)
    {
        if(i>=s.size())
        {
            res.push_back(curr);
            return;
        }
        for(int start = i;start<s.size();start++)
        {
            if(isvalid(s,i,start))
            {
                curr.push_back(s.substr(i,start-i+1));
                helper(res,curr,s,start+1);
                curr.pop_back();
            }
        }
    }
    bool isvalid(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};
