//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
   int helper(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(idx1 < 0 || idx2 < 0)
            return 0;
        int len = INT_MIN;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
            
        if(s1[idx1] == s2[idx2])
        {
            len = max(len, 1 + helper(idx1-1,idx2-1,s1,s2,dp));
        }
        else
        {
            len = max(len,max(helper(idx1,idx2-1,s1,s2,dp),helper(idx1-1,idx2,s1,s2,dp)));
        }
        return dp[idx1][idx2] = len;
    }
    int longestPalinSubseq(string &s) {
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return helper(s1.size()-1, s2.size() -1, s1,s2,dp);
        // code here
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends