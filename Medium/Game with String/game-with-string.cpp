//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
public:
    int minValue(string s, int k){
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        
        for(auto i:mp){
            pq.push({i.second, i.first});
        }
        
        while(k--){
            auto top=pq.top();
            pq.pop();
            int cntminus=top.first-1;
            if(cntminus>0){
                top.first=cntminus;
                pq.push(top);
            }
        }
        
        long long ans=0;
        while(!pq.empty()){
            ans+=pow(pq.top().first,2);
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends