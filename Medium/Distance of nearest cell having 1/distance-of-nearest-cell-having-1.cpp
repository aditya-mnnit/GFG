//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	   // vector<vector<int>>vis(n,vect/or<int>(m,0));
	      vector<vector<int>>ans(n,vector<int>(m,0));
	      queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	 
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        int x=q.front().first.first;
	        int y=q.front().first.second;
	        int d=q.front().second;
	        if(x+1<n&&grid[x+1][y]==0)
	        {
	            grid[x+1][y]=1;
	            q.push({{x+1,y},d+1});
	        }
	        if(x-1>=0&&grid[x-1][y]==0)
	        {
	            grid[x-1][y]=1;
	            q.push({{x-1,y},d+1});
	        }
	        if(y+1<m&&grid[x][y+1]==0)
	        {
	            grid[x][y+1]=1;
	            q.push({{x,y+1},d+1});
	        }
	        if(y-1>=0&&grid[x][y-1]==0)
	        {
	            grid[x][y-1]=1;
	            q.push({{x,y-1},d+1});
	        }
	        q.pop();
	        ans[x][y]=d;
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends