//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int a[],int n)
    {
        // Your code goes here
        vector<int>pos,neg;
        for(int i=0;i<n;i++)
        {
            if(a[i]>=0)
            pos.push_back(a[i]);
            else if(a[i]<0)
            neg.push_back(a[i]);
        }
        int k=0;
        for(int i=0;i<pos.size();i++)
        a[k++]=pos[i];
        for(int i=0;i<neg.size();i++)
        a[k++]=neg[i];
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends