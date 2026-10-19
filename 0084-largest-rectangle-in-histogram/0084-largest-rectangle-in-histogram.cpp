class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int nsi[n];
    nsi[n-1]=n;
    stack<int>st;
    st.push(n-1);
    // for nsi
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && heights[i]<=heights[st.top()]){
            st.pop();
        }
        if(st.size()==0) nsi[i]=n;
        else nsi[i]=st.top();
        st.push(i);
    }

    while(st.size()!=0){
        st.pop();
    }

    // for psi
    int psi[n];
    psi[0]=-1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 && heights[i]<=heights[st.top()]){
            st.pop();
        }
        if(st.size()==0) psi[i]=-1;
        else psi[i]=st.top();
        st.push(i);
    }
    int area = INT_MIN;
    for(int i=0;i<n;i++){
        int width=nsi[i]-psi[i]-1;
        area = max(area,width*heights[i]);
    }
    return area;
  }
};