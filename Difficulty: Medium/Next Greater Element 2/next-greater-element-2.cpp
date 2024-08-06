//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      using ll=long long int;
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        // code here
         arr.insert(arr.end(),arr.begin(),arr.end());
       ll n=arr.size();
        stack<ll>st;
        st.push(LONG_MAX);
        vector<ll>ans(n,-1);
        for(int i=arr.size()-1;i>=0;i--)
        {
            ll x=arr[i];
            while(st.top()<=x)
            {
                st.pop();
            }
            if(st.top()==LONG_MAX)
            ans[i]=-1;
            else
            {
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        vector<int>v;
        for(int i=0;i<n/2;i++)
        {
            v.push_back(ans[i]);
        }
        return v;
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
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends