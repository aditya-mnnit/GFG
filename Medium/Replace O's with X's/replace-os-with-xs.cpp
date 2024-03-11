//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool dfs(int i,int j,int n,int m,vector<vector<int>>&vis)
{
     if(i<0||j<0||i>=n||j>=m)
     return false;
     if(vis[i][j]==1)
     return true;
    vis[i][j]=1;
   bool a= dfs(i+1,j,n,m,vis);
 
    bool b= dfs(i-1,j,n,m,vis);
    
     bool c= dfs(i,j+1,n,m,vis);
    
     bool d=  dfs(i,j-1,n,m,vis);
    
     bool f=(a && b && c && d);
    
     
     return f;
     
}
void dfs2(int i,int j,int n,int m,vector<vector<int>>&vis2,vector<vector<char>>&grid)
{
     if(i<0||j<0||i>=n||j>=m)
     return ;
     if(vis2[i][j]==1)
     return ;
     vis2[i][j]=1;
    grid[i][j]='X';
    
    dfs2(i+1,j,n,m,vis2,grid);
 
    dfs2(i-1,j,n,m,vis2,grid);
    
     dfs2(i,j+1,n,m,vis2,grid);
    
    dfs2(i,j-1,n,m,vis2,grid);
    
     
     
    
     
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>>&board)
    {
        // code here
        //  int n=board.size();
        // int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,1));
           vector<vector<int>>vis2(n,vector<int>(m,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // cout<<board[i][j]<<" ";
                if(board[i][j]=='O')
                {
                vis[i][j]=-1;
                vis2[i][j]=-1;
                }
            }
            // cout<<"\n";
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==-1)
                {
                    
                if(dfs(i,j,n,m,vis))
                dfs2(i,j,n,m,vis2,board);
                
                }
            }
        }
        return board;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends