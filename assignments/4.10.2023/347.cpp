class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> map;

        for (int x: nums) map[x]++;
        int maxm = INT_MIN;

        unordered_map <int, vector<int>> nmap;

        for (pair<int, int> p: map) {
            nmap[p.second].push_back( p.first);
            maxm = max (maxm, p.second);
        }
        vector<int> ans;

        while (k!=0) {
            if (nmap.find(maxm) != nmap.end()) {
                for (int x: nmap[maxm]) {ans.push_back(x); k--;}
            }
            maxm--;
        }
        return ans;
    }
};