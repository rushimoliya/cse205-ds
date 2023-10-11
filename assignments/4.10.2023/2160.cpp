class Solution {
public:
    int minimumSum(int num) {
        vector<int> a;
        int temp = num;

        while(temp!=0){
            int t = temp%10;
            a.push_back(t);
            temp = temp/10;
        }
        sort(a.begin(),a.end());
        
        return (a[0]*10 + a[2] + a[1]*10 + a[3]);                
    }
};