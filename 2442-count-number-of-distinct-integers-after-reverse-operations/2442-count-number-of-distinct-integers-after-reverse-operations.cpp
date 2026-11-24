class Solution {
public:
    int reverse(int n){
        int r = 0;
        while(n>0){
            r = r*10 + (n%10);
            n = n/10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(reverse(nums[i]));
        }
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        return s.size();
    }
};