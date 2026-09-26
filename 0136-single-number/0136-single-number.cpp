/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;

        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        for(auto x : m) {
            if(x.second == 1) {
                return x.first;
            }
        }

        return -1;
    }
};
*/

// Using Bit Manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int XOR = 0;

        for(int i = 0; i < n; i++) {
            XOR = XOR ^ nums[i];
        }

        return XOR;
    
    }
};