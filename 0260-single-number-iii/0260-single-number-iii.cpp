// Using Hashmap

/*
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        vector<int> ans;
        for(auto p : mpp) {
            if(p.second == 1) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
*/

// Using Bit Manipulation

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;
        int n = nums.size();
        int rightmost = 0;

        for(int i = 0; i < n; i++) {
            XOR = XOR ^ nums[i];
        }

        rightmost = XOR & (-XOR);

        int b1 = 0, b2 = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] & rightmost) {
                b1 = b1 ^ nums[i];
            } else {
                b2 = b2 ^ nums[i];
            }
        }

        return {b1, b2};
    }
};
