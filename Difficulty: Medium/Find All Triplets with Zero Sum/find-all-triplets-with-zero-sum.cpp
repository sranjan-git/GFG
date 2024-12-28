//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        int n=arr.size();
        unordered_map<int,int>mapp;
        set<vector<int>>st;
        
        for(int i=0;i<n;i++){
            mapp[arr[i]]=i;
        }
        
        for(int j=0;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                int sum=arr[j]+arr[k];
                int rem=0-sum;
                
                if(mapp.find(rem)!=mapp.end()){
                    int i=mapp[rem];
                    if(i!=j && i!=k){
                        vector<int>temp{i,j,k}; 
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends