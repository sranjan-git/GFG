//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// } Driver Code Ends
//User function template for C++

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        //code here
        
    // Create hash maps to store counts of elements in both arrays
    unordered_map<int, int> countA, countB;

    // Populate countA
    for (int i = 0; i < N; i++) {
        countA[A[i]]++;
    }

    // Populate countB
    for (int i = 0; i < N; i++) {
        countB[B[i]]++;
    }

    // Compare counts of each element
    for (const auto& entry : countA) {
        int element = entry.first;
        int countInA = entry.second;
        int countInB = countB[element];

        if (countInA != countInB) {
            return false;
        }
    }

    return true;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<ll> arr(n,0),brr(n,0);
        
        // increase the count of elements in first array
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        
        
        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for(ll i=0;i<n;i++)
            cin >> brr[i];
        Solution ob;
        cout << ob.check(arr,brr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends