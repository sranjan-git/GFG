//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int M=1e9+7;
    int TotalWays(int n)
    {
        int a=1;
        int b=1;
        for(int i=1;i<n;i++){
           int c=a;
           a=(a+b)%M;
           b=(c)%M;
        }
        int temp=(a+b)%M;
        return (temp*1LL*temp)%M;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends