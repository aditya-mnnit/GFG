//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
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
    int subsequenceCount(string s, string t)
    {
      //Your code here
       int n=s.size();
        int m=t.size();
	    vector<vector<int>>dp(m,vector<int>(n,-1));
	   
	   
           int ans=f(0,0,m,n,t,s,dp);
            return ans;
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends