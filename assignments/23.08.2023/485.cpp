class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int temp =0;
        int ans = 0;

        for(int i= 0 ; i<nums.size();i++){
            if(nums[i] == 1){
                temp++;
            }
            else if (nums[i] == 0){
                if(temp > ans){
                    ans = temp;
                }
                temp = 0;
            }
        }
        if(temp > ans){
                    ans = temp;
                }
        return ans;
    }
};