class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        //int n2 = nums2.size();
        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            int t = 0;
            int m = -1;
            for(int k = i ; k < n ; k++ ){
                if(nums[k] > nums[i]){
                    m = nums[k];
                    t++;
                    break;
                }
            }
            if( t == 0){
                for(int j = 0 ; j < i ; j++){
                    if(nums[j] > nums[i]){
                    m = nums[j];
                    break;
                }
                }
            }
            ans.push_back(m);  
        }
        return ans;
    }
};
