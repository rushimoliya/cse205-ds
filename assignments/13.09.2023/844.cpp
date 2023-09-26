class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        stack<char> s1;

        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            if(ch == '#' && !s1.empty()){
                s1.pop();
            }else if(ch !='#'){
                s1.push(ch);
            }
        }

        int m = t.length();
        stack<char> s2;

        for(int i = 0 ; i < m ; i++){
            char ch = t[i];
            if(ch == '#' && !s2.empty()){
                s2.pop();
            }else if(ch !='#'){
                s2.push(ch);
            }
        }

        if(s1.size() == s2.size()){
            while(!s1.empty()){
                if(s1.top() == s2.top()){
                    s1.pop();
                    s2.pop();
                }else{
                    return false;
                }
            }
        }else{
            return false;
        }

        return true;

    }
};