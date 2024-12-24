//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
    
         int m = mat.size(); // Number of the rows
        int n = mat[0].size(); // number of the columns
        if(n == 0)
        {
            return false;
        }
        for(int i=0;i<m;i++)
        {
            int low = 0, high = n-1;
            while(low <= high)
            {
             int mid = low + (high-low)/2;
             if(mat[i][mid] == x)
             {
                 return true;
             }
             else if(mat[i][mid] > x)
             {
                 high = mid - 1;
             }
             else
             {
                 low = mid + 1;
             }
            }
        }
        return false;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends