class Solution {
public:
    void helper(vector<int>&ans,vector<vector<int>>&mat, int row, int col, bool flag){
        int m = mat.size();
        int n = mat[0].size();
        ans.push_back(mat[row][col]);
        if(row==m-1 && col==n-1) return; // last pushing
        else if(flag==true){ // upar jaoge
            if(row>0 && col<n-1) helper(ans,mat,row-1,col+1,true);
            else if(row==0 && col!=n-1) helper(ans,mat,row,col+1,false);
            else if(col==n-1) helper(ans,mat,row+1,col,false);
        }
        else if(flag==false){ // false mtlb niche jaoge
            if(col>0 && row<m-1) helper(ans,mat,row+1,col-1,false);
            else if(col==0 && row!=m-1) helper(ans,mat,row+1,col,true);
            else if(row==m-1) helper(ans,mat,row,col+1,true);
        }
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        helper(ans,mat,0,0,true);
        return ans;
    }
};