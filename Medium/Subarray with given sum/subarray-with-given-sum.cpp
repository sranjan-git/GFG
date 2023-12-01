//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        
    int first=0,mover=0,sum=0;
    while(first<=mover && mover<n){
        sum=sum+arr[mover];
        if(arr[mover]==s) return{mover+1,mover+1};/*for cases when there is say 1 is present  in the vector{ex-2,1,3,4} and sum is also 1 then it give  should give output -1 but as there is the element 1 it should give index of 1 ie {2,2}(no its not error :)here index start with 1...*/
    while(sum>s){/*while is used not IF because if IF was used its will work for 1 time no matter still the sum is greater than s ...so use while wisely :)*/
        sum=sum-arr[first];
        first++;
    } 
    mover++;
    if(s==0) return{-1};
    if(sum==s){
        return{first+1,mover/*not mover+1already done in mover++*/};
    }
    }
 return {-1};

} 
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends