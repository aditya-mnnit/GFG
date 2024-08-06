//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    using ll=long long int;
    long long subarrayRanges(int n, vector<int> &arr) {
        // code here
         ll mod=1e9+7;
        vector<ll>l(n);
        vector<ll>r(n);
        vector<ll>l1(n);
        vector<ll>r1(n);
        stack<pair<int,int>>st,st1;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top().first>=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            l[i]=n;
            else
            l[i]=st.top().second;
            st.push({arr[i],i});
        }
        for(int i=0;i<n;i++)
        {
            while(!st1.empty()&&st1.top().first>arr[i])
            {
                st1.pop();
            }
            if(st1.empty())
            r[i]=-1;
            else
            r[i]=st1.top().second;
            st1.push({arr[i],i});
        }
        while(!st.empty())
        st.pop();
         while(!st1.empty())
        st1.pop();
         for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top().first<=arr[i])
            {
                st.pop();
            }
            if(st.empty())
            l1[i]=n;
            else
            l1[i]=st.top().second;
            st.push({arr[i],i});
        }
        for(int i=0;i<n;i++)
        {
            while(!st1.empty()&&st1.top().first<arr[i])
            {
                st1.pop();
            }
            if(st1.empty())
            r1[i]=-1;
            else
            r1[i]=st1.top().second;
            st1.push({arr[i],i});
        }
        ll ans=0;
        ll ans1=0;
        for(int i=0;i<n;i++)
        {
            // cout<<l[i]<<" "<<r[i]<<"\n";
            ans+=((arr[i]%mod)*(l[i]-i)*(i-r[i]))%mod;
            ans1+=((arr[i]%mod)*(l1[i]-i)*(i-r1[i]))%mod;
        }
        return ans1-ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends