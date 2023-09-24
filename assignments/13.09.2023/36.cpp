class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for rows
        for(int i = 0 ; i < 9 ; i++){
            vector<char> temp = board[i]; 
            sort( temp.begin() , temp.end() );
            for(int j = 0 ; j < 8 ; j++){
                if( temp[j] != '.' && temp[j]==temp[j+1]){
                    return false;
                }
            }
        }
        // for columns
        for(int i = 0 ; i < 9 ; i++){
            vector<char> temp;
            for(int j = 0 ; j < 9 ; j++){
                temp.push_back(board[j][i]);
            }
            sort(temp.begin(),temp.end());
            for(int u = 0 ; u < 8 ; u++){
                if( temp[u] != '.' && temp[u]==temp[u+1]){
                    return false;
                }
            }
        }
        // for 3X3 boxes
        for(int i=0; i<9; i+=3) { 
	        for(int j=0; j<9; j+=3) {
	            vector<char> temp;
	            for(int k=0; k<3; k++) {
	                for(int l=0; l<3; l++) {
	                    temp.push_back(board[i+k][j+l]);
	                }
	            }
	            sort(temp.begin(), temp.end()); 
	            for(int k = 0 ; k < 9 ; k++) {
	                if(temp[k] == temp[k+1] && temp[k] != '.') {
	                    return false; 
	                }
	            }
	        }
    	}
        return true;
    }
};