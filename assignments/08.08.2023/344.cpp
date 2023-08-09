# include <bits/stdc++.h>

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        f(i,j,s);
    }
    void f(int i,int j ,vector<char>&s){
        if(i>=j) return;
        swap(s[i],s[j]);
        f(++i,--j,s);
    }
};