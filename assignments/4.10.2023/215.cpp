class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[i]);
        }
        sort(a.begin(),a.end());
        
        return a[a.size()-k];        
    }
};