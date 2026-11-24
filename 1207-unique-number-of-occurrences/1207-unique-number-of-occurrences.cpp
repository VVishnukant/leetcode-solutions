class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>freq(2001,0);
        int n = arr.size();
        for(int i=0;i<n;i++){
            int idx = arr[i]+1000;
            freq[idx]++;
        }
        sort(freq.begin(),freq.end());
        for(int i=0;i<2000;i++){
            if(freq[i]==0) continue;
            if(freq[i]==freq[i+1]) return false;
        }
        return true;
    }
};