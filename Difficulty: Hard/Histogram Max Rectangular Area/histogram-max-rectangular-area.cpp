//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    using ll=long long int;
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<ll>a(n);
        vector<ll>b(n);
        stack<ll>st;
        st.push(INT_MIN);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=INT_MIN&&arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            if(st.top()==INT_MIN)
            {
                a[i]=n;
            }
            else
            {
                a[i]=st.top();
            }
            st.push(i);
        }
        stack<ll>st1;
        st1.push(INT_MIN);
        for(int i=0;i<n;i++)
        {
             while(st1.top()!=INT_MIN&&arr[st1.top()]>=arr[i])
            {
                st1.pop();
            }
            if(st1.top()==INT_MIN)
            {
                b[i]=-1;
            }
            else
            {
                b[i]=st1.top();
            }
            st1.push(i);
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            // cout<<a[i]<<" "<<b[i]<<"\n";
            ans=max(ans,(arr[i]*(a[i]-b[i]-1)));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends