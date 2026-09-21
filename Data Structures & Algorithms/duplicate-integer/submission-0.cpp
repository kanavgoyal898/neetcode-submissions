class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Time Complexity: O(n * log n)
        // Space Complexity: O(1)
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i-1] == nums[i]) {
                return true;
            }
        }

        return false;
    }
};