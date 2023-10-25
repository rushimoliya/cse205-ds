class Solution {
public:
    int maxProduct(vector<int>& nums) {
        multimap<int, int> mp;
        for(int i=0;i<nums.size();i++) mp.insert(make_pair(nums[i],i));
        auto it=mp.rbegin();
        int i =it->second;
        it++;
        int j = it->second;
        return (nums[i]-1)*(nums[j]-1);
    }
};
