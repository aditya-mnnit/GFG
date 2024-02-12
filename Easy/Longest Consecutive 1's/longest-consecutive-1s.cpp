//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
using ll=long long int;
class Solution
{
    public:
    int maxConsecutiveOnes(int n)
    {
        // code here
        ll c=0;
        ll mx=0;
        for(int i=0;i<32;i++)
        {
            ll z=1LL<<i;
            if(z&n)
            c++;
            else
            {
                mx=max(mx,c);
                c=0;
            }
        }
        mx=max(mx,c);
        return mx;
        
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends