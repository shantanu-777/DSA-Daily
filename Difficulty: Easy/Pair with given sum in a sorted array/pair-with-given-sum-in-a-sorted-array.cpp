//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int start=0, end=arr.size()-1;
        int res=0;
        while(start<end){
            int sum=arr[start]+arr[end];
            if(sum==target){
                res++;
                int nextstart=start+1;
                while(nextstart<end && arr[nextstart]==arr[nextstart-1]){
                    nextstart++;
                    res++;
                }
                end--;
            }
            else if(sum<target) start++;
            else end--;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends