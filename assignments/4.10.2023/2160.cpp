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

    int minimumSum(int num) {
        vector<int> a;
        int temp = num;

        while(temp!=0){
            int t = temp%10;
            a.push_back(t);
            temp = temp/10;
        }
        mergeSort(a,0,a.size()-1);
        
        return (a[0]*10 + a[2] + a[1]*10 + a[3]);                
    }
};