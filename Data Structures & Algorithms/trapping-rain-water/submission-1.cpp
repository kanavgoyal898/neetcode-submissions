class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int prefixMaxHeight = 0;
        vector<int> suffixMaxHeight(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                suffixMaxHeight[i] = max(
                    suffixMaxHeight[i+1],
                    height[i+1]
                );
            }
        }

        int totalWater = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefixMaxHeight = max(prefixMaxHeight, height[i-1]);
                int water = max(
                    0,
                    min(prefixMaxHeight, suffixMaxHeight[i]) - height[i]
                );
                totalWater += water;
            }
        }

        return totalWater;
    }
};
