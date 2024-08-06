//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    using ll=long long int;
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<ll>st;
        st.push(LONG_MAX);
        vector<ll>ans(n,-1);
        for(int i=n-1;i>=0;i--)
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
        return ans;
        
        
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
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends