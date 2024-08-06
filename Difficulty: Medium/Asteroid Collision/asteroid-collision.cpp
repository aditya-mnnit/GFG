//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &arr) {
        // code here
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            int f=0;
            while(!st.empty()&&st.top()>0&&arr[i]<0)
            {
                if(abs(st.top())<abs(arr[i]))
                st.pop();
                else if(abs(st.top())==abs(arr[i]))
                {
                    f=1;
                    st.pop();
                    break;
                }
                else
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            st.push(arr[i]);
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends