/*
Geek has a rosarium and it has N*M slots, some of them are empty and some of them have roses. Given N*M character array consists of 0's and 1's. 0 represents an empty spot and 1 represents a rose. The task is to find the maximum number of adjacent roses in geek's rosarium. For a spot (i, j) adjacent spots are (i+1, j), (i-1, j), (i, j-1), (i, j+1), (i-1, j-1), (i-1, j+1), (i+1, j-1),  and (i+1, j+1).

Input: 
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space-separated integers N and M.
3. Next N lines consist of M characters.

Output: For each test case, print the maximum number of adjacent roses.

Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 100
3. '0' <= arr[i][j] <= '1'

Example:
Input:
2
2 2
10
01
3 4
1001
0011
0101

Output:
2
5
*/

//--------------------------------------------------------------------------------------------------------


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int area(vector<vector<char>>& grid, vector<vector<bool>>& seen,int i,int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || seen[i][j]|| grid[i][j]=='0')
    {
        return 0;
    }
    seen[i][j] = true;
    return(1+area(grid,seen,i+1,j)+area(grid,seen,i-1,j)
    +area(grid,seen,i,j-1)+area(grid,seen,i,j+1) + area(grid,seen,i-1,j-1) +area(grid,seen,i-1,j+1)
    +area(grid,seen,i+1,j-1)+area(grid,seen,i+1,j+1));
};
int main()
 {
	//code
	int t;
	cin>>t;
	for(int k = 0;k<t;k++)
	{
	    int n,m;
	    cin>>n;
	    cin>>m;
	    vector<vector<char>> grid(n,vector<char>(m));
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        {
	            cin>>grid[i][j];
	        }
	    }
	    vector<vector<bool>>seen(n,vector<bool>(m,false));
	    int ans=0 ;
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        {
	               ans = max(ans,area(grid,seen,i,j));
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
