//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        int n=arr.size(),m=brr.size();
        vector<double> bin(m);
        for(int i=0;i<m;i++){
            int x=brr[i];
            bin[i]=1.0*log2(x)/x;
        }
        sort(bin.begin(),bin.end());
        long long ans=0LL;
        for(auto x : arr){
            double val=1.0*log2(x)/x;
            int l=0,r=m-1;
            int validPairs=lower_bound(bin.begin(),bin.end(),val)-bin.begin();
            ans+=validPairs;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends