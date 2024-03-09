//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	 int solve(int arr[], int sum, int n) {
        bool t[n + 1][sum + 1];

        // Initialization
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0) {
                    t[i][j] = false;
                }
                if (j == 0) {
                    t[i][j] = true;
                }
            }
        }

        // Dynamic Programming
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = (t[i - 1][j - arr[i - 1]] || t[i - 1][j]);
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        // Find the maximum sum achievable in one subset
        int maxSum = 0;
        for (int j = sum / 2; j >= 0; j--) {
            if (t[n][j] == true) {
                maxSum = j;
                break;
            }
        }

        return maxSum;
    }

    int minDifference(int arr[], int n) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];
        }

        int s1 = solve(arr, s, n);
        return s - 2 * s1;
    }
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends