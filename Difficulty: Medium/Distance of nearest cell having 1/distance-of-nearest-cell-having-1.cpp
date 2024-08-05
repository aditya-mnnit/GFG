//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
         int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                    grid[i][j]=0;
                }
            }
        }
        
        int c=0;
        int k=1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto x=q.front();
                q.pop();
                int xx=x.first;
                int yy=x.second;
                if(xx>=0&&yy-1>=0&&xx<n&&yy-1<m&&vis[xx][yy-1]==0)
                {
                    grid[xx][yy-1]=k;
                     vis[xx][yy-1]=1;
                    q.push({xx,yy-1});
                }
                 if(xx>=0&&yy+1>=0&&xx<n&&yy+1<m&&vis[xx][yy+1]==0)
                {
                    grid[xx][yy+1]=k;
                     vis[xx][yy+1]=1;
                    q.push({xx,yy+1});
                }
                 if(xx+1>=0&&yy>=0&&xx+1<n&&yy<m&&vis[xx+1][yy]==0)
                {
                    grid[xx+1][yy]=k;
                     vis[xx+1][yy]=1;
                    q.push({xx+1,yy});
                }
                 if(xx-1>=0&&yy>=0&&xx-1<n&&yy<m&&vis[xx-1][yy]==0)
                {
                    grid[xx-1][yy]=k;
                    vis[xx-1][yy]=1;
                    q.push({xx-1,yy});
                }
            }
            k++;
            c++;
        }
    //   for(int i=0;i<n;i++)
    //   {
    //       for(int j=0;j<m;j++)
    //       {
    //           if(grid[i][j]==1)
    //           return -1;
    //       }
    //   }
       
        // return max(0,c-1);
        return grid;
     
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends