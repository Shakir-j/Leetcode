class Solution {
public:
    int lHist(vector<int>& heights) {
        int n = heights.size();

        vector<int> left(n, 0);
        vector<int> right(n, 0);

        stack<int> s;

        // right smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        // left smaller
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> pSum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (matrix[i][j] - '0');
                if (matrix[i][j] == '0') sum = 0;
                pSum[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, lHist(pSum[i]));
        }

        return maxArea;
    }
};