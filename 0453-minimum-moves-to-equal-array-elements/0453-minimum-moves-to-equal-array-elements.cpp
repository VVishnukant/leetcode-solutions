class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        int count = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            count += nums[i]-mini;
        }
        return count;
    }
};