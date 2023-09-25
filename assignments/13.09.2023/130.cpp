class Solution {
public:
    int navRow[4] = {-1 , 0 , 1 , 0};
    int navCol[4] = { 0 , 1 , 0 ,-1};

    void dfs( int row , int col , vector<vector<int>>& v , vector<vector<char>>& board){
        v[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + navRow[i];
            int ncol = col + navCol[i];
            if(nrow >= 0 && ncol >=0 && nrow<n && ncol<m && !v[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow , ncol , v , board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> v(n,vector<int>(m,0));
        // for row boder
        for(int i = 0 ; i < m ; i++){
            if( !v[0][i] && board[0][i] == 'O'){
                dfs( 0 , i , v , board);
            }
            if( !v[n-1][i] && board[n-1][i] == 'O'){
                dfs( n-1 , i , v , board);
            }
        }
        //for coloum boder
        for(int j = 0 ; j < n ; j++){
            if( !v[j][0] && board[j][0] == 'O'){
                dfs( j , 0 , v , board);
            }
            if( !v[j][m-1] && board[j][m-1] == 'O'){
                dfs( j , m-1 , v , board);
            }
        }
        
        // changing the 'O' to 'X'
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!v[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};