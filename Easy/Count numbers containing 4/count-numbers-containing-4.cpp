//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countNumberswith4(int n) {
        if(n==0) return 0;
        if(1<=n and n<=3) return 0;
        if(4<=n and n<=9) return 1;
        string str=to_string(n);
        int l=str.length();
        int x=int(n/pow(10,l-1));
        n=n%(int(pow(10,l-1)));
        if(x<4){
            return x*countNumberswith4(int(pow(10,l-1))-1)+countNumberswith4(n);
        }
        else if(x==4){
            return 4*countNumberswith4(int(pow(10,l-1))-1)+n+1;
        }
        else{
            return (x-1)*countNumberswith4(int(pow(10,l-1))-1)+int(pow(10,l-1))+countNumberswith4(n);
        }
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends