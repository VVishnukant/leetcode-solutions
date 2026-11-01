class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n = nums.size();
        vector<int>ngi(n);
        stack<int>st;
        st.push(n-1);
        ngi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && nums[i]>nums[st.top()]){
                st.pop();
            }
            if(st.size()==0) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }
        vector<int>ans;
        int j = 0; // TC-> O(n)
        for(int i=0;i<n-k+1;i++){
            if(j<i) j=i;
            int maxi=INT_MIN;
            while(j<i+k){
                maxi = nums[j];
                if(ngi[j] >= i+k) break;
                j = ngi[j];
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};