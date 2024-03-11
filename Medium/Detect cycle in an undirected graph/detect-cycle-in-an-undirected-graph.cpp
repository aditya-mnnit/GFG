//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<int>vis;
    int f=0;
    void dfs(int node,int par,vector<int> adj[])
    {
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(vis[x]==0)
            dfs(x,node,adj);
            else if(x!=par)
            f=1;
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vis.assign(V+1,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0)
            dfs(i,-1,adj);
            if(f==1)
            return true;
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends