//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
    if (n == 0) {
        return 0;
    }

    long long maxEndingHere = arr[0];
    long long minEndingHere = arr[0];
    long long maxProductSoFar = arr[0];

    for (int i = 1; i < n; i++) {
        // If the current element is negative, swap max and min
        if (arr[i] < 0) {
            swap(maxEndingHere, minEndingHere);
        }

        // Update max and min ending at the current position
        maxEndingHere = max((long long)arr[i], maxEndingHere * arr[i]);
        minEndingHere = min((long long)arr[i], minEndingHere * arr[i]);

        // Update the maximum product so far
        maxProductSoFar = max(maxProductSoFar, maxEndingHere);
    }

    return maxProductSoFar;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends