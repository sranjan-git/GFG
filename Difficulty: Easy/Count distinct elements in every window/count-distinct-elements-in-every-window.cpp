//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mpp;
        set<int>s;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            mpp[arr[i]]++;
            s.insert(arr[i]);
        }
        ans.push_back(s.size());
        for(int i=k;i<n;i++)
        {
            int first=i-k;
            mpp[arr[first]]--;
            if(mpp[arr[first]]==0) s.erase(arr[first]);
            mpp[arr[i]]++;
            s.insert(arr[i]);
            ans.push_back(s.size());
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends