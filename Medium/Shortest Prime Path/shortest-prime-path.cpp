//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
#define N 10002   
bool p[N];
    void buildSeive() {
        memset(p, 1, sizeof(p));
        p[0] = 0;
        p[1] = 0;

        for (int i = 2; i * i <= 10002; i++) {
            if (p[i] == 1) {
                for (int pos = i * 2; pos <= 10002; pos = pos + i) {
                    p[pos] = 0;
                }
            }
        }
    }
    int solve(int n1,int n2){   
        queue<pair<int,int>> q; 
        q.push({n1,0});
        buildSeive();

        while(!q.empty()){
           auto curr = q.front();
            int n = curr.first;
            int dist = curr.second;
            q.pop();

          
            if (n == n2)
                return dist;
                
            //1st digit
             for (int i = 1; i <= 9; i++) {
                int mm = i * 1000 + n % 1000;
                if (p[mm] ) {
                    q.push({mm, dist + 1});
                    p[mm] = 0;
                }
            }
            //2nd digit
             for (int i = 0; i <= 9; i++) {
                int mm = (n / 1000) * 1000 + i * 100 + n % 100;
                if (p[mm] ) {
                    q.push({mm, dist + 1});
                    p[mm] = 0;
                }
            }
            //3rd digit
            for (int i = 0; i <= 9; i++) {
                int mm = (n / 100) * 100 + i * 10 + n % 10;
                if (p[mm]  ) {
                    q.push({mm, dist + 1});
                    p[mm] = 0;
                }
            }
            //4th digit
            for (int i = 0; i <= 9; i++) {
                int mm = (n / 10) * 10 + i;
                if (p[mm] ) {
                    q.push({mm, dist + 1});
                    p[mm] = 0;
                }
            }
        }

        return -1;

    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends