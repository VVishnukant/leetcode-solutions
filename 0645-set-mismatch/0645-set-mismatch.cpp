class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            int idx = nums[i]-1;
            if(nums[i]==i+1 || nums[idx]==nums[i]) i++;
            else swap(nums[i],nums[idx]);
        }
        vector<int>ans(2);
        for(int i=0;i<n;i++){
            if(i+1 != nums[i]){
                ans[0]=nums[i];
                ans[1]=i+1;
            }
        }
        return ans;
    }
};