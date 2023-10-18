class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for(int i = 0; i < nums.size(); i++){

          auto it = freqMap.find(nums[i]);
          
          if(it != freqMap.end()){
            if(abs(i - it->second) <= k){
              return true;
            }
          }
          freqMap[nums[i]] = i;
        }
        return false;
    }
};