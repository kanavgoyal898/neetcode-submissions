class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> nums_;
        for (int i = 0; i < n; i++) {
            nums_.insert(nums[i]);
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            int length = 1;

            int num_L = nums[i] - 1;
            while (nums_.find(num_L) != nums_.end()) {
                length += 1;
                nums_.erase(num_L);
                num_L = num_L - 1;
            }

            int num_R = nums[i] + 1;
            while (nums_.find(num_R) != nums_.end()) {
                length += 1;
                nums_.erase(num_R);
                num_R = num_R + 1;
            }

            maxLength = max(length, maxLength);
        }

        return maxLength;
    }
};
