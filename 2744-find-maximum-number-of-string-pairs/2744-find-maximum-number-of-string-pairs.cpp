class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i=0;i<n-1;i++){
            string r = words[i];
            reverse(r.begin(),r.end());
            for(int j=i+1;j<n;j++){
                if(r==words[j]) count++;
            }
        }
        return count;
    }
};