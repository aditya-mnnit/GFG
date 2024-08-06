//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#include<ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 #define ordered_set tree<int, null_type,greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 using namespace __gnu_pbds;
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &indices){
        //write your code here
      
      vector<int>ans(n,0);
      ordered_set st;
      for(int i=n-1;i>=0;i--)
      {
          st.insert(arr[i]);
          int y=st.order_of_key(arr[i]);
          ans[i]=y;
              
          
      }
      
      vector<int>res(q);
      for(int i=0;i<q;i++)
      res[i]=ans[indices[i]];
      return res;
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends