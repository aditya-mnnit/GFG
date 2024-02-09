//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long f(int i,int j,int n,int s,int k,vector<vector<int>>&nums,vector<vector<vector<long long>>>&dp)
    {
        if(i>=n||j>=n||s>k)
        return 0;
        if(i==n-1&&j==n-1)
        {
        if(s+nums[i][j]==k)
        return 1;
        return 0;
        }
        if(dp[i][j][s]!=-1LL)
        return dp[i][j][s];
        long long x=s+nums[i][j];
        long long tk=f(i+1,j,n,x,k,nums,dp)+f(i,j+1,n,x,k,nums,dp);
        return dp[i][j][s]=tk;
        
    
        
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(n+1,vector<long long>(k+1,-1)));
        return f(0,0,n,0LL,k,arr,dp);
        
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends