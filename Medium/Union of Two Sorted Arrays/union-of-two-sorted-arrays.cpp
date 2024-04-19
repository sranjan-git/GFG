//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {   
        int itr1=0, itr2=0, t;
        vector<int> ans;
        ans.push_back(min(arr1[0],arr2[0]));
        while(itr1<n && itr2<m){
            t = *ans.rbegin();
            if(arr1[itr1]<arr2[itr2]){
                if(t<arr1[itr1])ans.push_back(arr1[itr1]);
                itr1++;
            }
            else if(arr1[itr1]>arr2[itr2]){
                if(t<arr2[itr2])ans.push_back(arr2[itr2]);
                itr2++;
            }
            else itr1++;
        }
        while(itr1<n){
            if(*ans.rbegin()<arr1[itr1])ans.push_back(arr1[itr1]);
            itr1++;
        }
        while(itr2<m){
            if(*ans.rbegin()<arr2[itr2])ans.push_back(arr2[itr2]);
            itr2++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends