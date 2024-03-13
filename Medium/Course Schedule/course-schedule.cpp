//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  int f=0;
  stack<int>st;
  vector<int>vis;
  void dfs(int node,int k,vector<vector<int>>&adj)
  {
      vis[node]=k;
      for(auto x:adj[node])
      {
          if(vis[x]==-1)
          dfs(x,k,adj);
          else
          {
              if(vis[x]==k)
              f=1;
          }
      }
      vis[node]=0;
      st.push(node);
  }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vis.assign(n+1,-1);
        vector<vector<int>>adj;
        adj.resize(n+1);
    
        for(int i=0;i<m;i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>ans;
        int c=1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            dfs(i,c++,adj);
            if(f==1)
            return ans;
            
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends