class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto t:s){
            if(t!='*'){
                st.push(t);
            }
            else{
                st.pop();
            }
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};