class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end());

        vector<int> start;
        vector<int> end;

        for(auto interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int n = intervals.size();

        int startIndex = 0;
        int endIndex = 0;

        int currentGroups = 0;
        int answer = 0;

        while(startIndex < n) {
            if(start[startIndex] <= end[endIndex]) {
                currentGroups++;
                answer = max(answer, currentGroups);
                startIndex++;
            } else {
                currentGroups--;
                endIndex++;
            }
        }

        return answer;
    }
};