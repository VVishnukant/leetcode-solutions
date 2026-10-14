class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";
        string ans = "";
        while(num!=0){
            int digit = min(sum,9);
            ans+=to_string(digit);
            sum-=digit;
            num--;
        }
        return ans;
    }
};