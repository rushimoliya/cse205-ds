class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int j = 0;
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            if(j == nums[i]){
                j++;
            }else{
                return j;
            }
        }

        return j++;
    }
};

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         int sumGiven = n*(n+1)/2;
//         int sum = 0;
//         for(int  i = 0 ; i < n ; i++){
//             sum += nums[i];
//         }
//         return sumGiven - sum;
//     }
// };