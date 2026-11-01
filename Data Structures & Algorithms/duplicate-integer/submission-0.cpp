class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> nums_;
        for (int i = 0; i < n; i++) {
            if (nums_.find(nums[i]) == nums_.end()) {
                nums_.insert(nums[i]);
            } else {
                return true;
            }
        }

        return false;
    }
};