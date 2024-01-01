//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
        if(nums.size()%2!=0)
        return false;
        
        unordered_set<int> s;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%k==0)
            count++;
            else
            {
                int rem=nums[i]%k;
                if(s.find(k-rem)==s.end())
                {
                    s.insert(rem);
                }
                else
                {
                    s.erase(k-rem);
                }
            }
        }
        return s.size()==0 && count%2==0;
      
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends