class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=abs(nums[i]);
            }
        }
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int i=0,j=n-1;
        while(i<j){
            sum+=pow(nums[j],2);
            sum-=pow(nums[i],2);
            i++,j--;
        }
        if(n%2==1)sum+=pow(nums[i],2);
        return sum;
    }
};