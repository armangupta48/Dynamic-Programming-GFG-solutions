/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words. 


Example 1:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilike"
Output: 1
Explanation:The string can be segmented as "i like".

â€‹Example 2:

Input:
n = 12
B = { "i", "like", "sam", "sung", "samsung", "mobile",
"ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as 
"i like samsung" or "i like sam sung".
 

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.


Expected time complexity: O(s2)
â€‹Expected auxiliary space: O(s) , where s = length of string A

 

Constraints:
1 <= N <= 12
1 <= s <=1000 , where s = length of string A
 The length of each word is less than 15.
*/
int helper(string str, vector<string> &B)
{
    if(str.size()==0)
    return 1;
    int ans = 0;
    for(int i = 0;i<str.size();i++)
    {
        string x = str.substr(0,i+1);
        if(std::find(B.begin(), B.end(), x) != B.end())
        {
            string r = str.substr(i+1);
            ans+=helper(r,B);
            
        }
        
    }
    return ans;
}
int wordBreak(string A, vector<string> &B) {
    //code here
    int a = helper(A,B);
    if(a>0)
    return 1;
    return 0;
}
