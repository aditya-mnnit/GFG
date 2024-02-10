//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int a[], int n) {
	    // code here
	    int f=-1;
	    for(int i=0;i<n;i++)
	    {
	       if(a[i]>0)
	       {
	           if(f!=-1)
	           {
	               a[f]=a[i];
	               f++;
	               a[i]=0;
	               
	           }
	       }
	       else if(a[i]==0)
	       {
	           if(f==-1)
	           f=i;
	       }
	    }
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends