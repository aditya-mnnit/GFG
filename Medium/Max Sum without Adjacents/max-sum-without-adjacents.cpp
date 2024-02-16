//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int i,int n,vector<int>&nums,vector<int>&dp)
	{
	    if(i>=n)
	    return 0;
	    if(dp[i]!=-1)
	    return dp[i];
	    int tk=nums[i]+f(i+2,n,nums,dp);
	    int nt=0+f(i+1,n,nums,dp);
	    return dp[i]=max(tk,nt);
	}
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return f(0,n,arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends