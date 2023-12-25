//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    
    vector<vector<int>>findNewMat(vector<vector<int>>& mat, int n, int col){
        vector<vector<int>>newMat;
        for(int i=1; i<n; i++){
            vector<int>temp;
            for(int j=0; j<n; j++){
                if(j!=col)
                    temp.push_back(mat[i][j]);
            }
            newMat.push_back(temp);
        }
        return newMat;
    }
    int dfs(vector<vector<int>>& mat, int n){
        if(n==2)return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
        int res=0,k=1;
        for(int i=0; i<n; i++){
            auto newMat = findNewMat(mat,n,i);
            res+= k*mat[0][i]*dfs(newMat,n-1);
            k=k*-1;
        }
        return res;
    }
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        if(n==1)return matrix[0][0];
        return dfs(matrix,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends