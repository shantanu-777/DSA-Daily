//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
       int maxlength=0;
       int n=arr.size();
       int sum=0;
       for (int i=0;i<n;i++){
           sum+=arr[i];
           
          if (sum==k){
            //   cout<<i<<" ";
              maxlength=max(maxlength,i+1);
          }
         else if (mp.find(sum-k)!=mp.end()){
                maxlength=max(maxlength,i-mp[sum-k]);
          }
           
           if (mp.find(sum)==mp.end()){
               mp[sum]=i;
           }
           
       }
       
       return maxlength;
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