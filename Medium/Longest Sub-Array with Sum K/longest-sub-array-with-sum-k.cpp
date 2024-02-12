//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
       unordered_map<int,int>mp;
       mp[0]=1;
       int mx=0;
       int s=0;
       for(int i=0;i<n;i++)
       {
           s+=a[i];
           if(mp[s-k]>0)
           mx=max(mx,i+2-mp[s-k]);
           if(mp[s]<=0)
           mp[s]=i+2;
       }
       return mx;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends