class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        vector<vector<bool>> dp(N+1,vector<bool>(sum+1,false));
        for(int i = 0;i<dp.size();i++)
        {
            for(int j = 0;j<dp[0].size();j++)
            {
                if(i==0&& j==0) dp[i][j] =true;
                else if(i==0) dp[i][j] = false;
                else if(j==0) dp[i][j] = true;
                else
                {
                    if(dp[i-1][j]==true)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        int val = arr[i-1];
                        if(j>=val)
                        {
                            if(dp[i-1][j-val]==true)
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
        return dp[N][sum];
    }
};
