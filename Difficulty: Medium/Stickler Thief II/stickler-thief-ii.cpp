//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[100001];
    int find(int i, int n, vector<int>& arr){
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        int take = arr[i] + find(i+2, n, arr);
        int notTake = find(i+1, n, arr);
        return dp[i] = max(take, notTake);
    }
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        int t1 = find(0, n-1, arr);
        memset(dp, -1, sizeof(dp));
        int t2 = find(1, n, arr);
        return max(t1, t2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends