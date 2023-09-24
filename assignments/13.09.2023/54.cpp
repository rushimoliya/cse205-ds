class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;

        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int till = row*col;

        int sR = 0;
        int sC = 0;
        int eR = row - 1;
        int eC = col - 1;

        while(count < till){
            for(int i = sC ; count < till && i <= eC ; i++){
                ans.push_back(matrix[sR][i]);
                count++;
            }
            sR++;
            
            for(int i = sR ; count < till && i <= eR ; i++){
                ans.push_back(matrix[i][eC]);
                count++;
            }
            eC--;

            for(int i = eC  ; count < till && i >= sC ; i--){
                ans.push_back(matrix[eR][i]);
                count++;
            }
            eR--;

            for(int i = eR ; count < till && i >= sR ; i--){
                ans.push_back(matrix[i][sC]);
                count++;
            }
            sC++;
        }
        return ans;    
    }
};