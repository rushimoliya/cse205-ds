class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();

      vector<vector<int>> newMat;

      newMat.resize(n);
      
      for(int i = 0 ; i < n ; i++){
          newMat[i].resize(n);
      }
      
      for(int  i = 0 ; i < n ; i++){
        int u=0;
        for(int  j = n - 1 ; j>=0 ; j--){
          newMat[i][u] = matrix[j][i];
          u++;
        }
      }
      matrix = newMat;
    }
};