//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

using ll=long long;
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>a, int n, long long s)
    {
        // Your code here
        int l=0;
        int r=0;
        ll su=0;
        ll mx=0;
        // if(s<a[0])
        // return {-1};
        if(s==0)
        {
            for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            return {i+1,i+1};
        }
        return {-1};
        }
        while(r<n)
        {
            su+=a[r];
            while(su>s)
            {
                su-=a[l];
                l++;
            }
            if(su==s)
           return {l+1,r+1};
            r++;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends