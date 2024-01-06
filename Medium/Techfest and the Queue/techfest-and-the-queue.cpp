//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	 int sumOfPowers(int a, int b){
        
        int count=0;
        
         for(int i=a;i<=b;i++)
         {
            int n=i;
            for(int j=2;j<=sqrt(n);j++)
            {
                while(n%j==0)
                {
                    count++;
                    n=n/j;
               }
            }
            if(n>=2)
            count++;
         }
        
        return count;
    }
};
    

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends