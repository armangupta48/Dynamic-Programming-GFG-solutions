Geek wants to build bridges between two banks of a river to help migrants to reach their homes. But, he can build a bridge only between two similar posts. Bridges can't overlap. The task is to find the maximum number of bridges geek can build. 

Note: Each of the posts is represented by either '*' or '@' or '#'.

Example: Let str1 = "*@#*", str2 = "*#". Then output will be 2.
* @ # *
|     / 
*  #

Input: 
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space-separated strings representing the posts in each bank

Output: For each test case, print the maximum number of bridges geek can build.

Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 100

Example:
Input:
2
*@#* *#
*** ##

Output:
2
0

using namespace std;

int main() {
	//code
	
	    string s1,s2;
	    int n ;
	    cin>>n;
	    for(int i = 0;i<n;i++)
	    {
	    cin>>s1;
	    cin>>s2;
	    vector<vector<int>> arr(s1.size()+1,vector<int>(s2.size()+1,0));
	    for(int j = 1;j<=s1.size();j++)
	    {
	        for(int k = 1;k<=s2.size();k++)
	        {
	            if(s1[j-1]==s2[k-1])
	            {
	                arr[j][k] = 1+arr[j-1][k-1];
	            }
	            else
	            {
	                arr[j][k] = max(arr[j-1][k],arr[j][k-1]);
	            }
	        }
	    }
	    cout<<arr[s1.size()][s2.size()]<<endl;
	    }
	return 0;
}
  
  
