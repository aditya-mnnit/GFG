//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // code here
         vector<vector<pair<int,int>>>adj;
         adj.resize(n);
        for(int i=0;i<m;i++)
        {
           
            
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        vector<int>dis(n,1e9);
        dis[0]=0;
        while(!q.empty())
        {
            auto p=q.top();
            int d=p.first;
            int el=p.second;
            q.pop();
            for(auto x:adj[el])
            {
                if(dis[x.first]>x.second+d)
                {
                    dis[x.first]=x.second+d;
                    q.push({dis[x.first],x.first});
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends