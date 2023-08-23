class Solution {
public:
    void swap(vector<int>& nums, int i, int idx) {
        int temp = nums[i];
        nums[i] = nums[idx];
        nums[idx] = temp;
    }
    void function(vector<vector<int>>& result, vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums, i, idx);
            function(result, nums, idx + 1);
            swap(nums, i, idx);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        function(result, nums, 0);
        return result;
    }
};