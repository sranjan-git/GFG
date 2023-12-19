//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        
    stack<char> s;

    // Traversing the expression
    for (char c : x) {
        // If the current character is an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        // If the current character is a closing bracket
        else {
            // If the stack is empty, brackets are not balanced
            if (s.empty()) {
                return false;
            }

            // Pop the top element from the stack
            char top = s.top();
            s.pop();

            // Check if the popped bracket corresponds to the current closing bracket
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If the stack is empty, brackets are balanced
    return s.empty();
    }
};



//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends