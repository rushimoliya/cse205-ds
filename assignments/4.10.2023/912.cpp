class Solution {
public:
    void mergeArr(vector<int>& a ,int s,int e){
        int mid = s + (e-s)/2;

        int left = s;

        int right = mid+1;

        vector<int> temp;

        while(left <= mid && right <= e){
            if(a[left] <= a[right]){
                temp.push_back(a[left]);
                left++;
            }else{
                temp.push_back(a[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(a[left]);
            left++;
        }
        while(right <= e){
            temp.push_back(a[right]);
            right++;
        }
        for(int i = s ; i<= e ; i++){
            a[i]=temp[i-s];
        }
    }

    void mergeSort(vector<int>& a ,int s,int e){
        if(s>=e) return;

        int mid = s + (e-s)/2;

        mergeSort(a,s,mid);

        mergeSort(a,mid+1,e);

        mergeArr(a,s,e);
        
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            a.push_back(nums[i]);
        }
        int n = a.size();
        mergeSort(a, 0 , n-1);

        return a;        
    }
};