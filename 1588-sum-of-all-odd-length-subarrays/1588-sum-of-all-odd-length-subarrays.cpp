// 1  1 4 2   1 4 2 5 3
// 4  4 2 5
// 2  2 5 3
// 5
// 3
// prefix sum = 1 5 7 12 15 // len+=2;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        for(int i=0;i<n;i++){
            int length=1;
            for(int j=i;j<n;j+=2){
                int x = 0;
                if(j-length>=0) x = arr[j-length];
                sum+=(arr[j]-x);
                length+=2;
            }
        }
        return sum;
    }
};