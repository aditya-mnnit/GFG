//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int s=0;
        mp[0]=1;
        int mx=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            s+=arr[i];
            if(mp[s-k]>0)
            {
                mx=max(mx,i-mp[s-k]+2);
            }
            if(mp[s]>0)
            continue;
            else
            mp[s]=i+2;
        }
        return mx;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends