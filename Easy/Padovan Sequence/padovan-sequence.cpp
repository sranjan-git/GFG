//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        const int mod = 1e9 + 7;
        int ans[n+1];
        ans[0]=1,ans[1]=1,ans[2]=1;
        if(n<=2)return 1;
        for(int i=3;i<=n;i++){
            ans[i]=(ans[i-2]+ans[i-3])%mod;
        }
        return ans[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends