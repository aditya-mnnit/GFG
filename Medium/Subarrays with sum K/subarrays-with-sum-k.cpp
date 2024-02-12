//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int a[], int n, int k)
    {
        // code here
         unordered_map<int,int>mp;
       mp[0]++;
       int c=0;
       int s=0;
       for(int i=0;i<n;i++)
       {
           s+=a[i];
           if(mp[s-k]>0)
         c+=mp[s-k];
          
           mp[s]++;
       }
       return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends