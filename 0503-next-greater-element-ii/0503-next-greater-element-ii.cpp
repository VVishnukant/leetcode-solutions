class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(st.size()>0 && nums[i%n]>=st.top()) st.pop();
            if(st.size()!=0) ans[i%n]=st.top();
            st.push(nums[i%n]); 
        }
        return ans;
    }
};