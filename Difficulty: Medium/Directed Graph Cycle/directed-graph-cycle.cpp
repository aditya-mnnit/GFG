//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    int f=0;
    vector<int>vis;
    void dfs(int node,vector<int>adj[])
    {
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(vis[x]==-1)
            dfs(x,adj);
            else if(vis[x]==1)
            {
                f=1;
                return ;
            }
            
        }
        if(f)
        return ;
        vis[node]=2;
        
        
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vis.assign(v+1,-1);
        for(int i=0;i<v;i++)
        {
            if(vis[i]==-1)
            dfs(i,adj);
            if(f)
            return true;
        }
        return false;
    
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends