class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[nums[i]] += 1;
        }

        vector<unordered_set<int>> buckets(n + 1);
        for (pair<int, int> vf : freq) {
            buckets[vf.second].insert(vf.first);
        }

        vector<int> topK;
        for (int i = n; i > 0; i--) {
            if (k == 0) {
                break;
            } else {
                if (buckets[i].size() > 0) {
                    for (int element : buckets[i]) {
                        topK.push_back(element);
                        k -= 1;
                    }
                }
            }
        }

        return topK;
    }
};
