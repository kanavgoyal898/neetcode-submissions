class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        
        int n = nums.size();

        unordered_set<int> nums_;
        for (int i = 0; i < n; i++) {
            if (nums_.find(nums[i]) != nums_.end()) {
                return true;
            } else {
                nums_.insert(nums[i]);
            }
        }

        return false;
    }
};