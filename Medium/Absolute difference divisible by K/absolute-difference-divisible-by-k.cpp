//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
using ll=long long ;
class Solution {
  public:
    long long countPairs(int n, int nums[], int k) {
        // code here
        ll s=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[nums[i]%k]++;
        for(auto x:mp)
        {
            s+=(x.second*(x.second-1))/2;
        }
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends