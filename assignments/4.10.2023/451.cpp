class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto i:s){
            mp[i]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }

        int j=0;
        while(!pq.empty()){
            auto i = pq.top();pq.pop();
            int temp = i.first;
            while(temp--){
                s[j++] = i.second;
            }
        }

        return s;
    }
};