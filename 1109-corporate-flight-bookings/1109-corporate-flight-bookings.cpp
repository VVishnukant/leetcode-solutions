class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        // 1  2    3   4  5
        // 10 45 -10 -20  0
        // 10 55  45  25  25
        int row = bookings.size();
        for(int i=0;i<row;i++){
            int start = bookings[i][0];
            ans[start-1] += bookings[i][2];
            int end = bookings[i][1];
            if(end<n) ans[end] -= bookings[i][2];
        }
        for(int i=1;i<n;i++){
            ans[i] += ans[i-1];
        }
        return ans;
    }
};