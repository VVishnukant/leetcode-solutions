class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && prices[i]<st.top()) st.pop();
            if(st.size()!=0 ) ans[i]=st.top();
            st.push(prices[i]);
        }
        for(int i=0;i<n;i++){
            ans[i] = prices[i]-ans[i];
        }
        return ans;
    }
};