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

    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        int n=arr.size(),n2=arr.size(),ans=0;
        vector<int> v;
        for(auto i:m){
            v.push_back(i.second);
        }
        mergeSort(v,0,v.size()-1);
        for(int i=v.size()-1;i>=0;i--){
            n2-=v[i];
            if(n2<=(n/2)){
                ans=ans+1;
                break;
            }
            else
                ans++;
        }
        return ans;
    }
};