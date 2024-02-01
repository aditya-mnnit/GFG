//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int i,int pre,string &s,vector<vector<int>>&dp)
	{
	    int n=s.size();
	    if(i==n)
	    {
	        return 1;

	    }
	    if(dp[i][pre+1]!=-1)
	    return dp[i][pre+1];
	    int tk=0,nt=0;
	    int su=0;
	    for(int j=i;j<n;j++)
	    {
	        su+=(s[j]-'0');
	        if(su>=pre)
	        {
	            tk+=f(j+1,su,s,dp);
	        }
	    }
	   
	   // cout<<i<<" "<<tk<<" "<<nt<<"\n";
	    return dp[i][pre+1]=tk+nt;
	}
	int TotalCount(string str){
	    // Code here
	    int n=str.size();
	    int su=0;
	    for(int i=0;i<n;i++)
	    su+=str[i]-'0';
	    vector<vector<int>>dp(n+1,vector<int>(901,-1));
	    return f(0,-1,str,dp);
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
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends