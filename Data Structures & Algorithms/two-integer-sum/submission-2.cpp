class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Time Complexity: O(n log n)
        // Space Complexity: O(1)

        int n = nums.size();
        
        vector<int> idx(n, -1);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        int i = 0;
        int j = n-1;

        while (i < j) {
            int sum = nums[idx[i]] + nums[idx[j]];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                return {min(idx[i], idx[j]), max(idx[i], idx[j])};
            }
        }

        return {};
    }
};
