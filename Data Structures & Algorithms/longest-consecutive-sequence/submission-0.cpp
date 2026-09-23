class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        
        int n = nums.size();

        unordered_set<int> nums_;
        for (int i = 0; i < n; i++) {
            nums_.insert(nums[i]);
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            int length = 0;
            if (nums_.find(nums[i]) != nums_.end()) {
                nums_.erase(nums[i]);
                length += 1;

                int start = nums[i] - 1;
                while (nums_.find(start) != nums_.end()) {
                    nums_.erase(start);
                    length += 1;
                    start = start - 1;
                }

                int end = nums[i] + 1;
                while (nums_.find(end) != nums_.end()) {
                    nums_.erase(end);
                    length += 1;
                    end = end + 1;
                }

                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};
