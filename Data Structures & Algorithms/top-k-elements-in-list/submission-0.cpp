class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Time Complexity: O(n log n)
        // Space Complexity: O(n)
        
        int n = nums.size();

        unordered_map<int, int> numsToFreq;
        for (int i = 0; i < n; i++) {
            numsToFreq[nums[i]] += 1;
        }

        vector<int> nums_;
        vector<int> freq_;
        for (pair<int, int> nf : numsToFreq) {
            nums_.push_back(nf.first);
            freq_.push_back(nf.second);
        }

        int m = nums_.size();
        vector<int> idx;
        for (int i = 0; i < m; i++) {
            idx.push_back(i);
        }

        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return freq_[i] > freq_[j];
        });

        vector<int> topK;
        for (int i = 0; i < k; i++) {
            topK.push_back(nums_[idx[i]]);
        }

        return topK;
    }
};
