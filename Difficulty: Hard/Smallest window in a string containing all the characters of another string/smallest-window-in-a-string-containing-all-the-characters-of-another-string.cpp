//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string smallestWindow(string s, string p) {
        int freqP[256] = {0}, freqS[256] = {0}, count = 0, start = 0, minLen = INT_MAX, startIdx = -1;
        for (char ch : p) freqP[ch]++;
        for (int end = 0; end < s.size(); end++) {
            freqS[s[end]]++;
            if (freqP[s[end]] && freqS[s[end]] <= freqP[s[end]]) count++;
            while (count == p.size()) {
                if (end - start + 1 < minLen) minLen = end - start + 1, startIdx = start;
                if (freqP[s[start]] && freqS[s[start]]-- == freqP[s[start]]) count--;
                start++;
            }
        }
        return startIdx == -1 ? "-1" : s.substr(startIdx, minLen);
    }
};



//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends