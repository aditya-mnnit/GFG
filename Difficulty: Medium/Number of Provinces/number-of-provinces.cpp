//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  vector<int>vis;
  void dfs(int node,vector<vector<int>> &adj)
  {
      vis[node]=1;
      for(auto x:adj[node])
      {
          if(vis[x]==-1)
          {
              dfs(x,adj);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vis.assign(V+1,-1);
        int c=0;
        vector<vector<int>>ad(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i==j)
                continue;
                else if(adj[i][j]==1)
                {
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(vis[i]==-1)
            {
                c++;
                dfs(i,ad);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends