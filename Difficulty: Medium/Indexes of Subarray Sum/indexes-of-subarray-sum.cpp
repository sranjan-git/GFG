//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
     int right = 0;
        int left = 0;
        
        long long sum = arr[left];
        while(right < n){
            if(sum == s){
                
                return {left+1,right+1};
            }
          else if(sum < s){
              right++;
              sum += arr[right];
          }
          else if(sum > s && left == right){
              left++;
              right++;
              sum = arr[left];
          }
          else{
              sum -= arr[left];
              left++;
          }
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends