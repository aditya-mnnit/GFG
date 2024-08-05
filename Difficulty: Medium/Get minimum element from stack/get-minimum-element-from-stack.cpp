//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> st;
    int mi;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(st.size()==0)
           return -1;
           //Write your code here
           return mi;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(st.size()==0)
           return -1;
           int x=st.top();
           st.pop();
           if(x<mi)
           {
               int k=mi;
               mi=2*mi-x;
               return k;
           }
           return x;
           
           
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(st.size()==0)
           {
               st.push(x);
               mi=x;
           }
           else if(x<mi)
           {
               st.push(2*x-mi);
               mi=x;
           }
           else
           {
               st.push(x);
           }
           //Write your code here
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends