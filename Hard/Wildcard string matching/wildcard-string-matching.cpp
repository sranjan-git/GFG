//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int i=0;
        int j=0;
        while(i<wild.size() && j<pattern.size()){
            if(wild[i]!=pattern[j] && wild[i]!='*' && wild[i]!='?'){
                return false;
            }else if(wild[i]!=pattern[j] && wild[i]=='?'){
                i++;
                j++;
            }else if(wild[i]!=pattern[j] && wild[i]=='*'){
                while(wild[i]=='*' || wild[i]=='?'){
                    i++;
                    j++;
                }
                while(pattern[j]!=wild[i]&&j<pattern.size()){
                    j++;
                }
            }else{
                i++;
                j++;
            }
        }
        if(i!=wild.size() || j!=pattern.size()) return false;
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends