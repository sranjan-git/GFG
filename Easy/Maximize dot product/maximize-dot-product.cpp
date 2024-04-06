//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int f(int i,int j,int n,int m,int a[],int b[],vector<vector<int>>&dp)
    {
        if(i>=n || j>=m)
        {
            return 0;
        }
        if(dp[i][j] !=-1)
        {
            return dp[i][j];
        }
        int take=a[i]*b[j] + f(i+1,j+1,n,m,a,b,dp);
        int notTake=0;
        if(n-1-i >= m-j) //notTake only when remaining elements in a are gretaer than or equal b's remaining elements
        {
         notTake = 0 + f(i+1,j,n,m,a,b,dp);
        }
        return dp[i][j]=max(take,notTake);
    }
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,a,b,dp);
    } 
};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends