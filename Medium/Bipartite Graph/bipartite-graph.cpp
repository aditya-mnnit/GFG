//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
unordered_map<int,int>mp;
int f=0;
void dfs(int node,int c, vector<int>adj[])
{
    if(mp[node]>0)
    {
        if(mp[node]==c)
        return;
        else
        f=1;
        return;
    }
    mp[node]=c;
    
    for(auto x:adj[node])
    {
        if(c==1)
        dfs(x,2,adj);
        else if(c==2)
        dfs(x,1,adj);
        
    }
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    for(int i=0;i<V;i++)
	    {
	        if(mp[i]<=0)
	        {
	            dfs(i,1,adj);
	            if(f==1)
	            return false;
	        }
	    }
	    return true;
	}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends