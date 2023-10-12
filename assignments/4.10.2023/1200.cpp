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

    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<int> a;
        vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++){
            a.push_back(arr[i]);
        }
        mergeSort(a,0,a.size()-1);

        int minDif=INT_MAX;
        for(int i=0;i<a.size()-1;i++){
            int temp=a[i+1]-a[i];
            minDif=min(minDif,temp);
        }

        for(int i=0;i<a.size()-1;i++){
            if(minDif == a[i+1]-a[i]){
               ans.push_back({a[i],a[i+1]});
            }
        }

        cout<< minDif;
        
        return ans;
    }
};