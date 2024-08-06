//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
using ll=long long int;
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        stack<ll>st;
        vector<ll>a(n);
        vector<ll>b(n);
        // for(int i=n-1;i>=0;i--)
        // {
        //     while(!st.empty()&&st.top()<=arr[i])
        //     {
        //         st.pop();
        //     }
        //     if(st.empty())
        //     {
        //         a[i]=arr[i];
        //     }
        //     else
        //     {
        //         a[i]=st.top();
        //     }
        //     st.push(arr[i]);
        // }
        // stack<ll>st1;
        // for(int i=0;i<n;i++)
        // {
        //     while(!st1.empty()&&st1.top()<=arr[i])
        //     {
        //         st1.pop();
        //     }
        //     if(st1.empty())
        //     {
        //         b[i]=arr[i];
        //     }
        //     else
        //     {
        //         b[i]=st1.top();
        //     }
        //     st1.push(arr[i]);
        // }
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,arr[i]);
            a[i]=mx;
        }
        mx=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
         mx=max(mx,arr[i]);
            b[i]=mx;
        }
        ll ans=0;
        //  for(int i=0;i<n;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n;i++)
        // {
        //     cout<<b[i]<<" ";
        // }
        for(int i=0;i<n;i++)
        {
            ans+=(min(a[i],b[i])-arr[i]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends