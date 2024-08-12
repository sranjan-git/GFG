//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int>ans;
       int n = arr1.size();
       int m = arr2.size();
       
       int i=0,j=0;
       while(i<n && j<m){
           if(arr1[i] < arr2[j]){
              ans.push_back(arr1[i]);
              i++;
           }
           else{
               ans.push_back(arr2[j]); 
               j++;
           }
       }
       
       while(i<n){
            ans.push_back(arr1[i]);
            i++;
       }
       
       while(j<m){
            ans.push_back(arr2[j]);
            j++;
       }
       
       int N=ans.size()-1;
       int p1=ans[N/2];
       int p2=ans[N/2+1];
       return p1+p2;
    }
};
//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends