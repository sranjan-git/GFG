//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
public:
    #define ll long long
    ll count = 0;
    void merge(ll arr[], ll l, ll m, ll r) {
        vector<ll> temp(r - l + 1);
        ll i = l, j = m + 1, k = 0;
        while (i <= m && j <= r) {
            if (arr[i] <= arr[j])  temp[k++] = arr[i++];
            else  count += m - i + 1, temp[k++] = arr[j++];
        }
        while (i <= m)    temp[k++] = arr[i++];
        while (j <= r)    temp[k++] = arr[j++];
        for (ll i = l, j = 0; j < r - l + 1; i++)  arr[i] = temp[j++];
    }

    void mergeSort(ll arr[], ll l, ll r) {
        if (l >= r)  return;
        ll mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    long long int inversionCount(long long  arr[], long long  n) {
        mergeSort(arr, 0, n - 1);
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends