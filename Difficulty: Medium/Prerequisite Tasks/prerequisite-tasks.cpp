//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 int f=0;
    vector<int>vis;
    void dfs(int node,vector<vector<int>>&adj)
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
	bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<vector<int>>adj(N+1);
	    vis.assign(N+1,-1);
	    for(int i=0;i<P;i++)
	    {
	        adj[pre[i].second].push_back(pre[i].first);
	    }
	      for(int i=0;i<N;i++)
        {
            if(vis[i]==-1)
            dfs(i,adj);
            if(f)
            return false;
        }
        return true;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends