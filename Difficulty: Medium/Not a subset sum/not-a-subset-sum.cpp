//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution

{
  public:
    long long findSmallest(vector<int> &arr)

{
        // Your code goes here.
        int ans = 1, n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            if(arr[i] > ans)
               break;   
            ans += arr[i];
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends