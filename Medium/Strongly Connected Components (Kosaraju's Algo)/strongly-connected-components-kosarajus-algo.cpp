//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&rtime)
	{
	    vis[node]=1;
	    for(auto x:adj[node])
	    {
	        if(vis[x]!=1)
	        {
	            dfs(x,vis,adj,rtime);
	        }
	    }
	    rtime.push_back(node);
	}
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        vector<int>rtime,rtime2;
        vector<int>vis(n,-1);
        // dfs(0,vis,adj,rtime);
       
         for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                 dfs(i,vis,adj,rtime);
            }
        }
         vis.assign(n,-1);
        vector<vector<int>>adj2(n);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                adj2[adj[i][j]].push_back(i);
            }
        }
        int c=0;
        reverse(rtime.begin(),rtime.end());
        for(int i=0;i<n;i++)
        {
            if(vis[rtime[i]]==-1)
            {
                c++;
                dfs(rtime[i],vis,adj2,rtime2);
            }
        }
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends