//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
    vector<int> result(2, 0);

    // Traverse the array and mark the presence of elements
    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1;

        // If the element at index is negative, it means we have seen this index before, so it's the repeating number
        if (arr[index] < 0) {
            result[0] = abs(arr[i]);
        } else {
            // Mark the presence of the element by making it negative
            arr[index] = -arr[index];
        }
    }

    // Find the missing number
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            result[1] = i + 1;
            break;
        }
    }

    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends