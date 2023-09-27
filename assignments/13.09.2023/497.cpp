class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        for(int i = 0 ; i < n1 ; i++){
            int m = -1;
            for(int j = 0 ; j < n2 ; j++){
                if(nums1[i] == nums2[j]){
                    for(int k = j ; k < n2 ; k++ ){
                        if(nums2[k] > nums1[i]){
                            m = nums2[k];
                            break;
                        }
                    }
                    ans.push_back(m);  
                }
            }
        }
        return ans;
    
    }
};