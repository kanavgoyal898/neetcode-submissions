class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int suffixMaxHeight = 0;
        vector<int> prefixMaxHeight(n, 0);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                prefixMaxHeight[i] = max(
                    prefixMaxHeight[i-1],
                    height[i-1]
                );
            }
        }

        int totalWater = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                suffixMaxHeight = max(suffixMaxHeight, height[i+1]);
                int water = max(
                    0,
                    min(prefixMaxHeight[i], suffixMaxHeight) - height[i]
                );
                totalWater += water;
            }
        }

        return totalWater;
    }
};
