//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto distance = [](const vector<int>& p) -> double { 
            return sqrt(p[0] * p[0] + p[1] * p[1]); 
        };
    
        auto comp = [distance](const vector<int>& p1, const vector<int>& p2) -> bool { 
            return distance(p1) < distance(p2); 
        };
    
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);
        
        for (const auto& point : points) {
            maxHeap.push(point);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
    
        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
    
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends