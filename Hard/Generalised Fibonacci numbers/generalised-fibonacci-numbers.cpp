//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<long long >>multiply(vector<vector<long long>>a,vector<vector<long long>>b,long long  m){
      
      vector<vector<long long>>res(3,vector<long long>(3,0));
      
      for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
              long long sum=0;
              for(int k=0;k<3;k++){
                  sum+=((a[i][k]%m)*(b[k][j]%m))%m;
                  sum%=m;
              }
           res[i][j]=sum;
          }
      }
      return res;
  }
      
   vector<vector<long long>>sol(long long n,long long m,vector<vector<long long>>cof){
      if(n==1){
          return cof;
      }
      
      vector<vector<long long >>res=sol(n/2,m,cof);
      
      res=multiply(res,res,m);
      
      if(n&1)res=multiply(res,cof,m);
      
      return res;
  }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
       if(n<=2)return 1;
        vector<vector<long long>>cof={{a,b,1},{1,0,0},{0,0,1}};
        
        vector<vector<long long>>base={{1},{1},{c}};
        
        vector<vector<long long>>res=sol(n-2,m,cof);
        res=multiply(res,base,m);
        
        return (res[0][0])%m;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends