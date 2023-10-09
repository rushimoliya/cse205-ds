class Solution {
public:
    void mergeArr(vector<int> &arr, int s, int e)
    {
        int mid = s + (e - s) / 2;
        vector<int> a;
        int left = s;
        int right = mid + 1;

        while (left <= mid && right <= e)
        {
            if (arr[left] <= arr[right])
            {
                a.push_back(arr[left]);
                left++;
            }
            else
            {
                a.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            a.push_back(arr[left]);
            left++;
        }
        while (right <= e)
        {
            a.push_back(arr[right]);
            right++;
        }

        for (int i = s; i <= e; i++)
        {
            arr[i] = a[i - s];
        }
    }

    void mergeSort(vector<int> &arr, int s, int e)
    {
        if(s>=e) return;
        int mid = s + (e - s) / 2;
        // left one
        mergeSort(arr, s, mid);
        // right one
        mergeSort(arr, mid + 1, e);

        mergeArr(arr, s, e);
    }
    void selectionSort(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            int min = i;
            for(int j =i+1 ; j<nums.size();j++){
                if(nums[j]<nums[min]) min = j;
            }
            swap(nums[min],nums[i]);
        }
    }

    void bubbleSort(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            for(int j=0 ; j<nums.size()-i-1;j++){
                if(nums[j]<nums[j+1]) swap(nums[j],nums[j+1]);
            }
        }
    }

    void insertionSort(vector<int>& arr){
        for(int i=1;i<arr.size();i++){
            int key = arr[i];
            int j= i-1;
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
    }

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        // selectionSort(nums);
        // insertionSort(nums);
        mergeSort(nums,0,n-1);
        return nums[n/2];
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int count = 0;
//         int candidate = 0;

//         for (int num : nums) {
//             if (count == 0) {
//                 candidate = num;
//             }
            
//             if (num == candidate) {
//                 count++;
//             } else {
//                 count--;
//             }
//         }        
//         return candidate;
//     }
// };