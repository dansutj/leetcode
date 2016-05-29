class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> queens(n, string(n, '.')); 
        backTracking(queens, 0, n);
        return result;
    }
    
    void backTracking(vector<string>& queens, int row, int n)
    {
        if(row == n)
        {
            result.push_back(queens);
            return;
        }
        for(int col = 0; col < n; col++)
        {
            if(isValid(queens, row, col, n))
            {
                queens[row][col] = 'Q';
                backTracking(queens, row + 1, n);
                queens[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& queens, int row, int col, int n)
    {
        for(int i = 0; i < row; i++)
        {
            if(queens[i][col] == 'Q')
                return false;
        }
        
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if(queens[i][j] == 'Q')
                return false;
        }
        
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if(queens[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
private:
    vector<vector<string>> result;
};