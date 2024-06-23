//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) 
    {
        vector<int> result;
        
        stack<int> temp;
        
        int tempOpen=0;
        
        for(int i=0 ; i<str.size() ; i++)
         {
             if(str[i]=='(')
              {
                  tempOpen++;
                  result.push_back(tempOpen);
                  temp.push(tempOpen);
              }
              else if(str[i]==')')
               {
                   result.push_back(temp.top());
                   temp.pop();
                   
               }
         }
 
        return result ;
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends