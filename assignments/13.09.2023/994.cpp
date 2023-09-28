class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> v(n,(vector<int>(m,0)));

        queue<pair<pair<int,int> ,int>> q; // structur= {{r,c} , t}

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    v[i][j] = 2;
                }
            }
        }

        int navRow[4] = {-1 , 0 , 1 , 0};
        int navCol[4] = { 0 , 1 , 0 ,-1};
        int tm = 0 ;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm  = max(tm , t);
            q.pop();

            for(int i = 0 ; i <4 ; i++){
                int nr = r + navRow[i];
                int nc = c + navCol[i];
                if(nr>=0 && nr<n  && nc>=0 && nc < m && v[nr][nc] !=2 && grid[nr][nc] == 1){
                    q.push({{nr,nc}, t+1});
                    v[nr][nc] = 2;

                }
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && v[i][j]!=2){
                return -1;
                }
            }
        }
        return tm;

    }
};