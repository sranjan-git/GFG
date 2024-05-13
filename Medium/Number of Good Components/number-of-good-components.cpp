//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        int ans=0;
        vector<int> vis(v+1);
        vector<vector<int>> graph(v+1);
        for(auto e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        for(int i=1;i<=v;i++){
            int vCount=0,eCount=0;
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    vCount++;
                    eCount+=graph[node].size();
                    for(int adj:graph[node]){
                        if(!vis[adj]){
                            vis[adj]=1;
                            q.push(adj);
                        }
                    }
                }
                ans+=(eCount == vCount*(vCount-1));
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends