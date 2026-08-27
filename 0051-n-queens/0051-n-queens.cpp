class Solution {
public:
    void solve(int row,vector<string>&board,vector<vector<string>>&ans,
               vector<int>&columnUsed,vector<int>&leftDiagonalUsed,
               vector<int>&rightDiagonalUsed,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(columnUsed[col]==0 &&
               leftDiagonalUsed[n-1+col-row]==0 &&
               rightDiagonalUsed[row+col]==0){

                board[row][col]='Q';

                columnUsed[col]=1;
                leftDiagonalUsed[n-1+col-row]=1;
                rightDiagonalUsed[row+col]=1;

                solve(row+1,board,ans,columnUsed,
                      leftDiagonalUsed,rightDiagonalUsed,n);

                board[row][col]='.';

                columnUsed[col]=0;
                leftDiagonalUsed[n-1+col-row]=0;
                rightDiagonalUsed[row+col]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        vector<int>columnUsed(n,0);
        vector<int>leftDiagonalUsed(2*n-1,0);
        vector<int>rightDiagonalUsed(2*n-1,0);

        solve(0,board,ans,columnUsed,
              leftDiagonalUsed,rightDiagonalUsed,n);

        return ans;
    }
};