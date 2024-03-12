//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int c=0;
  bool dfs(int i,int j,int n,int m,vector<vector<int>>&grid, vector<vector<int>>&vis)
{
    if(i<0||j<0||i>=n||j>=m)
    return true;
    if(grid[i][j]==0||vis[i][j]==1)
    return false;
    vis[i][j]=1;
    bool t=dfs(i+1,j,n,m,grid,vis);
    bool b=dfs(i-1,j,n,m,grid,vis);
    bool l=dfs(i,j+1,n,m,grid,vis);
    bool r=dfs(i,j-1,n,m,grid,vis);
    bool ans=(t||b||l||r);
    if(!ans)
    c++;
    return (t||b||l||r);
}
int dfs2(int i,int j,int n,int m,vector<vector<int>>&grid)
{
      if(i<0||j<0||i>=n||j>=m||grid[i][j]==0)
      return 0;
    grid[i][j]=0;
       
      return 1+dfs2(i+1,j,n,m,grid)+dfs2(i-1,j,n,m,grid)+dfs2(i,j+1,n,m,grid)+ dfs2(i,j-1,n,m,grid);
     
    
}
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
          vector<vector<int>>vis(n,vector<int>(m,0));
          int ans=0;
           for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               
                if(grid[i][j]==1&&vis[i][j]==0)
                {
                    c=0;
                    if(dfs(i,j,n,m,grid,vis)==false)
                    {
                        // ans+=dfs2(i,j,n,m,grid);
                        ans+=c;
                        c=0;
                    }
                }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends