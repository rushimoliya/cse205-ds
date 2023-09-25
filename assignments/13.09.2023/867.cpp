class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> newMat;

        newMat.resize(col);
        
        for(int i = 0 ; i < col ; i++){
            newMat[i].resize(rows);
        }

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                newMat[j][i] = matrix[i][j];
            }    
       }
       return newMat;
    }
};