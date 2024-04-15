//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     int help(vector<int>&b,int ele,int n){
        int l=0;
        int r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(b[mid]>ele){
                r=mid-1;
            }
            else{
                ans=max(ans,mid);
                l=mid+1;
            }
        }
        return ans==-1?0:ans+1;
    }
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        sort(b.begin(),b.end());
        vector<int> ans;
        for(auto it:query){
            int x=a[it];
            ans.push_back(help(b,x,n));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends