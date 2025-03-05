//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*You are required to complete this method*/
class Solution {
  public:
    // Function to calculate the maximum area of a rectangle
    // in the given matrix.
    int maxArea(vector<vector<int>> &mat) {
        // Your code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            v[i][0]=mat[i][0];
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==1)
                v[i][j]=mat[i][j]+v[i][j-1];
                else
                v[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                   int mi=INT_MAX;
                   int c=0;
                   for(int k=i;k>=0;k--)
                   {
                       c++;
                       mi=min(mi,v[k][j]);
                       ans[k][j]=max(ans[k][j],mi*c);
                   }
                }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                res=max(res,ans[i][j]);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(mat) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends