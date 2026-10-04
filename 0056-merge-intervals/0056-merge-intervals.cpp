class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < n; i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(end >= s) {
                end = max(end, e);
                continue;
            }
            result.push_back({start,end});
            start = s;
            end = e;
        }

        result.push_back({start,end});

        return result;
    }
};