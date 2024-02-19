//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    // unordered_map<string,int>mp;
    int f(int i,string &s,map<string,int>&mp,vector<int>&dp)
    {
        int n=s.size();
        if(i>=n)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        string tp="";
        // int mi=1e9;
        // int tk=1e9,nt=1e9;
        for(int j=i;j<n;j++)
        {
            tp+=(s[j]);
            if((mp.find(tp)!=mp.end())&&f(j+1,s,mp,dp))
            {
                return dp[i]=1;
            }
        //     nt=1+f(j+1,s,mp,dp);
        //   mi= min(mi,min(tk,nt));
        }
        return dp[i]=0;
    }
public:
    int wordBreak(string s, vector<string> &nums) {
        //code here
        int n=s.size();
        map<string,int>mp;
        for(auto x:nums)
        mp[x]++;
        vector<int>dp(n+1,-1);
       int x=f(0,s,mp,dp);
      if(x==0)
      return 0;
      return 1;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends