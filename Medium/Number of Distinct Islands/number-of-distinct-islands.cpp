//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<pair<int,int>>v;
  void dfs(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis)
  {
      if(i<0||j<0||i>=n||j>=m)
      return ;
      if(grid[i][j]==0||vis[i][j]==1)
      return ;
      vis[i][j]=1;
      v.push_back({i,j});
      dfs(i-1,j,n,m,grid,vis);
       dfs(i+1,j,n,m,grid,vis);
        dfs(i,j-1,n,m,grid,vis);
         dfs(i,j+1,n,m,grid,vis);
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        map<set<pair<int,int>>,int>mp;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&vis[i][j]==-1)
            {
                v.clear();
                dfs(i,j,n,m,grid,vis);
                set<pair<int,int>>st;
                for(auto x:v)
                {
                    st.insert({x.first-i,x.second-j});
                }
                mp[st]++;
                
            }
            }
        }
        int ans=mp.size();
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends