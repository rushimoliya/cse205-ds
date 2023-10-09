class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<int> a;
        vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++){
            a.push_back(arr[i]);
        }
        sort(a.begin(),a.end());

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