class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        long long curr=1;
        int i=rowIndex;
        for(int j=0;j<=i;j++){
            ans.push_back(curr);
            curr=curr*(i-j)/(j+1);
        }
        return ans;
    }
};