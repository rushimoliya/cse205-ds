class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[i]);
        }
        sort(a.begin(),a.end());

        int sum = 0;
        for(int i=0;i<a.size();i=i+2){
            sum = sum + a[i];
        }
        return sum;

    }
};