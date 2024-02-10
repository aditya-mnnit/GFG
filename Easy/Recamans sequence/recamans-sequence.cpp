//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  vector<int> recamanSequence(int n){
        unordered_set<int> set;
        
        vector<int> dp(n,-1);
        
        dp[0] = 0;
        set.insert(0);
        
        for(int i=1;i<n;i++){
            int x = dp[i-1] - i;
            if(x > 0 && set.find(x) == set.end()){
                dp[i] = x;
            }
            else{
                x = dp[i-1] + i;
                dp[i] = x;
            }
            set.insert(dp[i]);
        }
        return dp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends