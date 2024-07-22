//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
             vector<vector<vector<int>>>v(n+1);
             for(int i=0;i<edges.size();i++)
             {
                 vector<int>t;
                int x=edges[i][0];
                int y=edges[i][1];
                v[x].push_back({y,0});
                v[y].push_back({x,1});
             }
             deque<int>q;
             q.push_back(src);
             vector<int>dis(n+1,INT_MAX);
             dis[src]=0;
             while(!q.empty())
             {
                 int sr=q.front();
                 q.pop_front();
                 for(auto x:v[sr])
                 {
                     if(dis[x[0]]>dis[sr]+x[1])
                     {
                     dis[x[0]]=dis[sr]+x[1];
                    //  cout<<x[0]<<" "<<x[1]<<"\n";
                     if(x[1]==0)
                     {
                     q.push_front(x[0]);
                     }
                     else
                     {
                         q.push_back(x[0]);
                     }
                     }
                 }
             }
             if(dis[dst]==INT_MAX)
             return -1;
             return dis[dst];
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends