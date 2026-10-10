class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;
        int n = cardPoints.size();

        // To find the lsum
        for(int i = 0; i <= k-1; i++) {
            lsum = lsum + cardPoints[i];
            maxSum = lsum;
        }

        // To find the lsum + rsum by descreasing lsum and increasing rsum
        int rightIndex = n-1;
        for(int i = k - 1; i >= 0; i--) {
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rightIndex];
            rightIndex -= 1;

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;

    }
};