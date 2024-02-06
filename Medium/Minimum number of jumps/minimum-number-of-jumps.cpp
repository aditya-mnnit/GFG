//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int a[], int n){
        // Your code here
        int mx=0;
        int c=0;
       int limit=a[0];
       int i=0;
       mx=a[0];
       if(n==1)
       return 0;
       while(true)
       {
           if(i==n)
           break;
           if(i>limit)
           {
               if(mx<i)
               return -1;
               c++;
               limit=mx;
               
           }
           mx=max(mx,i+a[i]);
           if(mx>=n-1)
           {
               if(i==0)
               c+=1;
               else
               c+=2;
               return c;
           }
           i++;
           
       }
       return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends