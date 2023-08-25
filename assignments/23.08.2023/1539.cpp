class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        vector<int> ans;
        int u = 0;
        int  n = arr[arr.size()-1] +k;
        cout<<n;
        for (int i=1 ; i<=(n) ; i++){

            if( arr[u] == i ){
                if(u<arr.size()-1){
                    u++;
                }
            }else {
                ans.push_back(i);
            }
        }
    // if(ans.size()==0){
    //     return arr[n]+k;
    // }
    return ans[k-1];
    //return 0;
    }
};