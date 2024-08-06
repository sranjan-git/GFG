//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
     
        int cnt=0;
         if(str[0] == '0' or str[0] == '.')
        {
            return 0;
        }
        for(int i=0;i<str.size();i++) {
            string s="";
     
            while(str[i]!='.' && i<str.size()) {
               
              
                s+=str[i]; 
                
            
                if(stoi(s)>255 || stoi(s)<0) {
                return 0;
                break;
               
            }
            i++;
            }
              if(str[i]==str[i+1] and str[i]=='.') return 0;
            cnt++;
            
    
        }
        if(cnt!=4) return 0;
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends