class Solution {
public:
    stack<char> s1;
    bool match(char c1 , char c2){
        if(c2 == '}' && c1 == '{') return true; 
        if(c2 == ']' && c1 == '[') return true; 
        if(c2 == ')' && c1 == '(') return true; 

        return false;
    }

    bool isValid(string s) {

        int n = s.length();

        for(int i=0 ; i<n ; i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                s1.push(ch);
            }
            if(ch == ')' || ch == '}' || ch == ']'){
                if(s1.empty()){
                    return false;
                }
                else{
                    char ch1 = s1.top();
                    if(match(ch1 , ch)){
                        s1.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        if(s1.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};