class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int nsi[n];
        nsi[n-1] = n;
        stack<int>st;
        st.push(n-1);

        // right smaller
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()) nsi[i]=n;
            else{
                nsi[i]=st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }

        // left smaller
        int psi[n]; 
        psi[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) psi[i]=-1;
            else{
                psi[i]=st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int width = nsi[i]-psi[i]-1;
            int area = heights[i]*width;
            ans = max(ans,area);
        }
        return ans;
    }
};