//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string t, vector<string>& l) {
        // Code here
        map<string,int>mp;
        for(int i=0;i<l.size();i++)
        {
            mp.insert({l[i],1});
        }
        queue<pair<string,int>>q;
        q.push({s,0});
        while(!q.empty())
        {
            
                auto it=q.front();
                q.pop();
                string tp=it.first;
                
                int op=it.second;
                if(tp==t)
                {
                    return op+1;
                }
                for(int j=0;j<tp.size();j++)
                {
                    string p=tp;
                for(int i=0;i<26;i++)
                {
                    char ch=(char)('a'+i);
                    p[j]=ch;
                    if((tp!=p)&&mp.find(p)!=mp.end())
                    {
                        q.push({p,op+1});
                        mp.erase(p);
                    }
                }
                
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends