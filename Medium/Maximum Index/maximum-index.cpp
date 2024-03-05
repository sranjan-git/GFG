//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        int maxdiff;
        int i,j;
        int *lmin=new int[n];
        int *rmax=new int[n];
        lmin[0]=a[0];
        for(int i=1; i<n; i++){
            lmin[i]=min(a[i],lmin[i-1]);
        }
        rmax[n-1]=a[n-1];
        for(int j=n-2; j>=0; j--){
            rmax[j]=max(a[j],rmax[j+1]);
        }
        maxdiff=-1;
        i=0;
        j=0;
        while(i<n && j<n){
            if(lmin[i]<=rmax[j]){
                maxdiff=max(maxdiff,j-i);
                j=j+1;
            }
            else{
                i=i+1;
            }
        }
        return maxdiff;
    }
};





//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends