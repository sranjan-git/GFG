//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	       long long sumBitDifferences(int arr[], int n) {
        // code here
        long long ans = 0;
        for(int bit = 0; bit < 32 ; bit++)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if((arr[i]&(1<<bit)))
                {
                    cnt++;
                }
            }
            ans += 2LL*cnt*(n-cnt);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends