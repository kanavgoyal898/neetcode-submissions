class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;

        int prefixMaxHeight = height[i++];
        int suffixMaxHeight = height[j--];

        int totalWater = 0;
        while (i <= j) {
            int water = 0;
            if (prefixMaxHeight < suffixMaxHeight) {
                water = max(
                    0,
                    prefixMaxHeight - height[i]
                );
                prefixMaxHeight = max(prefixMaxHeight, height[i++]);
            } else {
                water = max(
                    0,
                    suffixMaxHeight - height[j]
                );
                suffixMaxHeight = max(suffixMaxHeight, height[j--]);
            }
            totalWater += water;
        }

        return totalWater;
    }
};
