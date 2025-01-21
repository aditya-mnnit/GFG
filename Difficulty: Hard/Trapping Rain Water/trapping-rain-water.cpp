//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int l=0;
        int r=n-1;
        int ans=0;
        int mxl=0,mxr=0;
        while(l<r)
        {
            if(arr[l]<=arr[r])
            {
                mxl=max(mxl,arr[l]);
                ans+=mxl-arr[l];
                l++;
            }
            else
            {
                mxr=max(mxr,arr[r]);
                ans+=mxr-arr[r];
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends