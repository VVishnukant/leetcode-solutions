class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        int n = arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        unordered_set<int>s;
        for(auto x : m){
            int freq = x.second;
            if(s.find(freq)!=s.end()) return false;
            else s.insert(freq);
        }
        return true;
    }
};