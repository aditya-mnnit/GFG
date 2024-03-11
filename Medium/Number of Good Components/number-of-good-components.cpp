//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>>adj2;
  vector<int>vis;
  int c=0,e=0;
  void dfs(int node)
  {
      vis[node]=1;
      c++;
      for(auto x:adj2[node])
      {
          e++;
          if(vis[x]==-1)
          {
              
              dfs(x);
          }
      }
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        // int n=adj.size();
        // vector<vector<ll>>adj2(V);
        // adj2.clear();
        adj2=adj;
        vis.assign(V+1,-1);
        e=0,c=0;
        // for(int i=0;i<adj.size();i++)
        // {
        //     adj2[adj[i][0]].push_back(adj[i][1]);
        //     adj2[adj[i][1]].push_back(adj[i][0]);
        // }
        int ans=0;
        for(int i=1;i<=V;i++)
        {
            if(vis[i]==-1)
            {
                e=0,c=0;
                dfs(i);
                e/=2;
                // cout<<e<<" "<<c<<"\n";
                if(e==((c*(c-1))/2))
                ans++;
                
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends