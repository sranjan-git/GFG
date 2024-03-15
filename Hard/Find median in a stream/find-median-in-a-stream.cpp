//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    double median=0;
    
    int check(int a,int b){
        if(a==b) return 0;
        else if(a>b) return 1;
        else return -1;
    }
    void insertHeap(int &x)
    {
        switch(check(maxi.size(),mini.size())){
            case 0:
            if(x>median){
                mini.push(x);
                median=mini.top();
            }
            else{
                maxi.push(x);
                median=maxi.top();
            }
            break;
            
            case 1:
            if(x > median){
                mini.push(x);
                median=(maxi.top()+mini.top())/2;
            }
            else{
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(x);
                median=(maxi.top()+mini.top())/2;
            }
            break;
            
            case -1:
            if(x > median){
                maxi.push(mini.top());
                mini.pop();
                mini.push(x);
                median=(maxi.top()+mini.top())/2;
            }
            else{
                maxi.push(x);
                median=(maxi.top()+mini.top())/2;
            }
            break;
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        return median;
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends