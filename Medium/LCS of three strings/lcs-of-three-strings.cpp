//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int i,int j,int k,string &s,string &t,string &p,vector<vector<vector<int>>>&dp)
    {
        if(i>=s.size()||j>=t.size()||k>=p.size())
        return 0;
        int tk=0;
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        if(s[i]==t[j]&&s[i]==p[k])
        tk=1+f(i+1,j+1,k+1,s,t,p,dp);
        else
        {
            tk=max(f(i+1,j,k,s,t,p,dp),max(f(i,j+1,k,s,t,p,dp),f(i,j,k+1,s,t,p,dp)));
        }
        return dp[i][j][k]=tk;
    }
        int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
        {
            // your code here
            vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
            
            return f(0,0,0,a,b,c,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends