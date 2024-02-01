//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int s=0;
        int n= str.size();
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='-'&&i==0)
            {
                f=1;
                // cout<<"hi";
                continue;
            }
            if(!isdigit(str[i]))
            return -1;
            int x=(int)(str[i]-'0');
            s=(s*10)+x;
        }
        if(f==1)
        s*=-1;
        return s;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends