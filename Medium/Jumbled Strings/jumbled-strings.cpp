//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
	int TotalWays(string str){
	    // Code here
	    int n=str.size();
	    vector<vector<int>>dp(5,vector<int>(n,-1));
	    string x="GEEKS";
	    int m=5;
           int ans=f(0,0,m,n,x,str,dp);
            return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalWays(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends