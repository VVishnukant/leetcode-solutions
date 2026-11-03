class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = nums[n/2];
        for(int i=0;i<n;i++){
            if(nums[i]>mini) count += nums[i]-mini;
            else if(nums[i]<mini) count+=mini-nums[i];
        }
        return count;
    }
};