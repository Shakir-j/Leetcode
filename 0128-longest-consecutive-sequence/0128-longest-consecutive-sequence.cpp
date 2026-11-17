class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int longest = 0;
        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        for(auto i : s) {
            if(s.find(i - 1) == s.end()) {
                int start = i;
                count = 0;

                while(s.find(start) != s.end()) {
                    start++;
                    count++;

                    longest = max(longest, count);
                }
            }
        }

        return longest;
    }
};