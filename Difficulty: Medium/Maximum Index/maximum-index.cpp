//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
using ll=long long int;
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<ll>a(n),b(n);
        int mx=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mx=min(mx,arr[i]);
            a[i]=mx;
        }
        mx=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            mx=max(mx,arr[i]);
            b[i]=mx;
        }
        int i=0,j=0;
         mx=0;
        while(i<n&&j<n)
        {
            if(b[j]>=a[i])
          {
              mx=max(mx,j-i+1);
              j++;
          }
          else
          i++;
            
        }
        return mx-1;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends