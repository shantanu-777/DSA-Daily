//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int, int> ump;
        for(int i = 0; i<k;i++)
        {
            ump[arr[i]]++;
        }
        vector<int> ans;
        ans.push_back(ump.size());
        
        for(int i = k; i<arr.size(); i++)
        {
            int last_element = arr[i-k];
            ump[last_element]--;
            if(ump[last_element]==0)ump.erase(last_element);
            ump[arr[i]]++;
            ans.push_back(ump.size());
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends