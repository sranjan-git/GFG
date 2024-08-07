//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int index=-1;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    break;
                }
                count++;        
            }
            if(count==mat[0].size()){
                index=i;
                break;
            }
        }
        if(index==-1){
            return -1;
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][index]==0 && i!=index){
                return -1;
            }
        }
        return index;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends