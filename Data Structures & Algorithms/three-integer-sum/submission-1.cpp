class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> threeSums;

        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                int target = 0 - nums[i];
                int l = i + 1;
                int r = n - 1;
                while (l < r) {
                    int target_ = nums[l] + nums[r];

                    if (target_ < target) {
                        l++;
                    } else if (target_ > target) {
                        r--;
                    } else {
                        threeSums.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                    }

                    while (l < r && l > i + 1 && nums[l] == nums[l-1]) {
                        l++;
                    }

                    while (l < r && r < n - 1 && nums[r] == nums[r+1]) {
                        r--;
                    }
                }
            }
        }

        return threeSums;
    }
};
