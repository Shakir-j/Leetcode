class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n > 1) {
            cnt += n & 1; // (n & 1) is the odd check
            n = n >> 1; // This is same as (n/2)
        }

        if(n == 1) cnt += 1;

        return cnt;
    }
};

// STL Function : return __builtin_popcount(n);