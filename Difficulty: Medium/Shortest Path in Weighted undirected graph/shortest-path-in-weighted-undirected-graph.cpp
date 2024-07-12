//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        set<pair<int,pair<int,vector<int>>>> st;
        vector<int> tp;
        tp.push_back(1);
        st.insert({0,{1,tp}});
        vector<int> dist(n,1e9);
        dist[0]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]-1].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]-1].push_back({edges[i][0],edges[i][2]});
        }
        vector<int> ans;
        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second.first;
            vector<int> ls=it.second.second;
            st.erase(it);
            
            for(auto jt:adj[node-1]){
                int vt=jt.first;
                int wt=jt.second;
                if(dis+wt<dist[vt-1]){
                    dist[vt-1]=dis+wt;
                    vector<int> temp=ls;
                    temp.push_back(vt);
                    if(vt==n){
                        ans=temp;
                    }
                    st.insert({dist[vt-1],{vt,temp}});
                }
            }
        }
        if(dist[n-1]==1e9){
            return {-1};
        }
        else{
            reverse(ans.begin(),ans.end());
                ans.push_back(dist[n-1]);
                reverse(ans.begin(),ans.end());
                return ans;
        }
        }
    };

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends