//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod=1e9+7;
int f(int i,int j,int n,int m,string &s,string &t,vector<vector<int>>&dp)
{
    if(i==n)
    return 1;
    if(j==m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int tk=0;
    if(s[i]==t[j])
    tk+=(f(i+1,j+1,n,m,s,t,dp)+f(i,j+1,n,m,s,t,dp))%mod;
    else
    {
        tk+=f(i,j+1,n,m,s,t,dp)%mod;
    }
    return dp[i][j]=tk%mod;
}
    int countWays(string s, string t){
        // code here
        int n=s.size();
        int m=t.size();
    
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans;
        if(n<=m)
        {
             vector<vector<int>>dp(n,vector<int>(m,-1));
            ans=f(0,0,n,m,s,t,dp);
        }
         else
         {
             vector<vector<int>>dp(m,vector<int>(n,-1));
             ans=f(0,0,m,n,t,s,dp);
              
         }
         return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}
// } Driver Code Ends