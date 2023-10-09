class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> a;
        for(int i=0;i<heights.size();i++){
            a.push_back(heights[i]);
        }
        sort(a.begin(),a.end());

        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=a[i]){
                cnt++;
            }
        }
        return cnt;

    }
};