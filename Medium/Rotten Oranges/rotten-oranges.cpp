//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        if(q.empty())
        return 0;
        int c=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            if(x-1>=0&&grid[x-1][y]==1)
            {
                grid[x-1][y]=2;
                q.push({x-1,y});
            }
            if(x+1<n&&grid[x+1][y]==1)
            {
                grid[x+1][y]=2;
                q.push({x+1,y});
            }
            if(y+1<m&&grid[x][y+1]==1)
            {
                grid[x][y+1]=2;
                q.push({x,y+1});
            }
            if(y-1>=0&&grid[x][y-1]==1)
            {
                grid[x][y-1]=2;
                q.push({x,y-1});
            }
            }
            c++;
        }
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(grid[i][j]==1)
              return -1;
          }
      }
       
        return c-1;
       
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends