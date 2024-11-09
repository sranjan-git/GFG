//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        string num1="";
        string num2="";
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                num1+='0'+arr[i];
                
            }else{
                num2+='0'+arr[i];
                
            }
        }
        
        int n=num1.size();
        int m=num2.size();
        int i=n-1;
        int j=m-1;
        int carry=0;
        int d1,d2;
        string ans="";
        int temp;
        while(i>-1||j>-1||carry){
            
            if(i>-1){
             d1=num1[i]-'0';
            }else{
                d1=0;
            }
            if(j>-1){
            d2=num2[j]-'0';
            }else{
                d2=0;
            }
            temp=(d1+d2+carry);
            int n=temp%10;
            
            ans+=n+'0';
            carry=temp/10;
            i--;
            j--;
            
        }
        
        int k=0;
        reverse(ans.begin(),ans.end());
        for(k=0;k<ans.size();k++){
            if(ans[k]!='0'){
                break;
            }
        }
        return ans.substr(k);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends