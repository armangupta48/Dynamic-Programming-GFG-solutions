Given a rod of length N inches and an array of prices that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

 

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.
Example 2:

Input:
N=8
Price []={3,   5,   8,   9,  10,  17,  17,  20}
Output: 24
Explanation: 
The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*3=24. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.

 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 1000
1 <= Ai <= 105

 

//lr method 
int cutRod(int price[], int n) {
    vector<int> np(n+1,0);
    for(int i = 0;i<n;i++)
    {
        np[i+1] = price[i];
    }
    vector<int> dp(np.size(),0);
    dp[0] = 0;
    dp[1] = np[1];
    for(int i = 2;i<dp.size();i++)
    {
        dp[i] = np[i];
        int li = 1;
        int ri = i-1;
        while(li<=ri)
        {
            if(dp[li]+dp[ri]>dp[i])
            {
                dp[i] = dp[li]+dp[ri];
            }
            li++;
            ri--;
        }
    }
    return dp[dp.size()-1];
    
}
