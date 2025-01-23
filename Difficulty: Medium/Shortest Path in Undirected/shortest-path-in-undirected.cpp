//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,src});
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!q.empty())
        {
            auto p=q.top();
            int d=p.first;
            int el=p.second;
            q.pop();
            for(auto x:adj[el])
            {
                if(dis[x]>1+d)
                {
                    dis[x]=1+d;
                    q.push({dis[x],x});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dis[i]==1e9)
            dis[i]=-1;
        }
        return dis;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends