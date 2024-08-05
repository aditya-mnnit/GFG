//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                if(!st.empty()&&st.top()=='(')
                {
                    st.pop();
                    continue;
                }
                else
                return false;
            }
            if(s[i]=='}')
            {
                if(!st.empty()&&st.top()=='{')
                {
                    st.pop();
                    continue;
                }
                 else
                return false;
            }
            if(s[i]==']')
            {
                if(!st.empty()&&st.top()=='[')
                {
                    st.pop();
                    continue;
                }
                 else
                return false;
            }
            else
            st.push(s[i]);
        }
        if(st.size()==0)
        return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends