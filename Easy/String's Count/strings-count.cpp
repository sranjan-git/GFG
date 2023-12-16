//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    long long int count=0;
    
    count+=1;//(n)a
    count+=n;// (n-1)a and 1b
    if(n>=2)
    {
        count+=((n)*(n-1)/2);//(n-2)a and 2b
    }
    count+=n;//(n-1)a and 1c
    if(n>=2)
    {
        count+=((n)*(n-1));//(n-2)a and 1b and 1c
    }
    if(n>=3)
    {
        count+=(n*(n-1)*(n-2))/2;//(n-3)a and 2b and 1c
    }
    return count;
    
};
    










