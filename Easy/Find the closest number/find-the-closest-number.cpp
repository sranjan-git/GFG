//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
    int idx = upper_bound(arr, arr+n, k) - arr;
        int d1 = 1e9, d2=1e9;
        if(idx<n){
            d1 = abs(k-arr[idx]);
        }
        if(idx>0){
            d2 = abs(k-arr[idx-1]);
        }
        return d1<d2 ?  arr[idx] : (d1==d2? arr[idx] : arr[idx-1]);
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends