//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        
const int MOD = 1000000007;


    if (n == 0) return 0;
    if (n == 1) return k;

    long long prev0 = k; // dp[i-1][0]
    long long prev1 = 0; // dp[i-1][1]

    for (int i = 2; i <= n; ++i) {
        long long curr0 = (prev0 + prev1) * (k - 1) % MOD;
        long long curr1 = prev0;

        // Update previous values
        prev0 = curr0;
        prev1 = curr1;
    }

    // The final answer is the sum of ways to paint the last post with different colors
    // and the ways to paint the last post with the same color as the second-to-last post
    return (prev0 + prev1) % MOD;
}

};


//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends