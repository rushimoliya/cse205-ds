class Solution {
public:
    string customSortString(string order, string s) {
        string str ="";
        vector<int> vis(s.length(),0);

        for(int i=0;i<order.length();i++){
            char ch = order[i];

            for(int j=0;j<s.length();j++){
                if(ch == s[j]){
                    str = str + s[j];
                    vis[j] = 1;
                }
            }
        }        

        for(int i=0;i<s.length();i++){
            if(vis[i] == 0){
                str=str+s[i];
            }
        }
        return str;
    }
};