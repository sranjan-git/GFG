//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        vector<int> binary;
        while(n)
        {
            binary.push_back(n&1);
            n=n/2;
        }
        reverse(binary.begin(), binary.end());
        for(int i = 1; i < binary.size(); i++)
        {
            binary[i] = binary[i]^binary[i-1];
        }
        int counter = binary.size()-1;
        int ans = 0;
        for(int i = 0; i < binary.size(); i++)
        {
            ans += binary[i] * (pow(2,counter));
            counter--;
        }
        return ans;
        // Your code here
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends