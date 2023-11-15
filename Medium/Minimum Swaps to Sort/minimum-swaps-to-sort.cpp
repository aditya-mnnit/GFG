//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    vector<vector<int>>adj;
    vector<int>vis;
    int dfs(int node)
    {
        vis[node]=1;
        
        for(auto x:adj[node])
        {
            if(vis[x]==0)
            return 1+dfs(x);
        }
        return 0;
        
    }
    //below
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    adj.resize(n+1);
	    vis.assign(n+1,0);
	    vector<pair<int,int>>v;
	    for(int i=0;i<n;i++)
	    v.push_back({nums[i],i});
	    sort(v.begin(),v.end());
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second!=i)
	        {
	            adj[i].push_back(v[i].second);
	            adj[v[i].second].push_back(i);
	        }
	    }
	    int s=0;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i]==0)
	        s+=dfs(i);
	    }
	    return s;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends