class Solution {
public:

    void mergeArr(vector<int>& a ,int s,int e){
        int mid = s + (e-s)/2;
        int l = s;
        int r = mid+1;
        vector<int> t;
        while(l<=mid && r<=e){
            if(a[l]<=a[r]){
                t.push_back(a[l]);
                l++;
            }else{
                t.push_back(a[r]);
                r++;
            }
        }

        while(l<=mid){
            t.push_back(a[l]);
            l++;
        }
        while(r<=e){
            t.push_back(a[r]);
            r++;
        }

        for(int i=s ; i<=e ; i++){
            a[i]=t[i-s];
        }
    }

    void mergeSort(vector<int>& a ,int s,int e){
        if(s>=e) return;

        int mid = s + (e-s)/2;

        mergeSort(a, s , mid);
        
        mergeSort(a, mid+1 , e);

        mergeArr(a,s,e);
    }

    int missingNumber(vector<int>& nums) {
        int j = 0;
        mergeSort(nums,0,nums.size()-1);

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