class Solution {
public:
//  Decreasing monotonic deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n = nums.size();
        if(k==1) return nums;
        for(int i=0;i<n;i++){
            while(dq.size()>0 && nums[i]>nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            int j = i-k+1; // i-j+1 = k
            while(j>dq.front()) dq.pop_front();
            if(i>=k-1) ans.push_back(nums[dq.front()]);

        }
        return ans;
    }
};