//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int a[],int n)
{
//Your code here
int s=0;
for(int i=0;i<n;i++)
{
    s+=a[i];
}
int su=0;
for(int i=0;i<n;i++)
su+=(a[i]*i);
int mx=su;
for(int i=n-1;i>=0;i--)
{
    su+=s;
    su-=(a[i]*n);
    mx=max(mx,su);
}
return mx;
}