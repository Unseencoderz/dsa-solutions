class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int mx = 0;

        while (i < j) {
            int h = min(heights[i], heights[j]);
            int w = j - i;
            mx = max(mx, h * w);

            // Move the pointer with smaller height
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return mx;
    }
};