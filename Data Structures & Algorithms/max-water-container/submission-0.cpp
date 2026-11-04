class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0;
        int j = n - 1;

        int maxArea_ = 0;
        while (i < j) {
            int area_ = min(heights[i], heights[j]) * (j - i);
            maxArea_ = max(maxArea_, area_);

            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxArea_;
    }
};
