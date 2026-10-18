class Solution {
public:
    int reverseBits(int n) {
        int bits[32];
        for (int i = 0; i < 32; i++) {
            bits[i] = (n >> i) & 1;
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | bits[i];
        }
        return (int)ans;
    }
};

