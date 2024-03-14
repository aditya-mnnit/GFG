//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<int>dis(n,1e9);
        dis[src]=0;
        set<pair<int,int>>st;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        st.insert({0,src});
        while(!st.empty())
        {
            auto it=*st.begin();
            int di=it.first;
            int ele=it.second;
            st.erase(it);
            for(auto x:adj[ele])
            {
                int ne=di+1;
                int child=x;
                
                if(dis[child]>ne)
                {
                    dis[child]=ne;
                    st.insert({ne,child});
                }
            }
        }
        for(int i=0;i<n;i++)
        if(dis[i]==1e9)
        dis[i]=-1;
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends