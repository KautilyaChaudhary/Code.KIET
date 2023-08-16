class Solution {
public:
void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftr,vector<int> &upd,vector<int> &lwrd,int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }

    for(int ro=0;ro<n;ro++)
    {
        if(leftr[ro]==0 && upd[n-1 +col-ro]==0 && lwrd[col + ro]==0)
        {
            board[ro][col]='Q';
            leftr[ro]=1;
            upd[n-1 +col-ro]=1;
            lwrd[col + ro]=1;
            solve(col+1,board,ans,leftr,upd,lwrd,n);
            board[ro][col]='.';
            leftr[ro]=0;
            upd[n-1 +col-ro]=0;
            lwrd[col + ro]=0;

        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int> leftr(n,0),upd(2*n -1,0),lwrd(2*n-1,0);
        solve(0,board,ans,leftr,upd,lwrd,n);
return ans;

    }
};