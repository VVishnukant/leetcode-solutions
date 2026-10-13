class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int a=i+1;
            if(n%a==0) sum=sum+pow(nums[i],2);
        }
        return sum;
    }
};