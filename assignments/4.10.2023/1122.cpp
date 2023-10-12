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

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> vis(arr1.size(),0);

        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<arr1.size();j++){
                if(arr2[i] == arr1[j]){
                    ans.push_back(arr1[j]);
                    vis[j] = 1; 
                }
            }
        }

        vector<int> temp;
        for(int i=0;i<arr1.size();i++){
            if(vis[i] == 0){
                temp.push_back(arr1[i]);
            }
        }
        mergeSort(temp,0,temp.size()-1);

        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }

        return ans;
    }
};