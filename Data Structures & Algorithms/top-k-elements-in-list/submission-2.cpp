class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        vector<unordered_set<int>> buckets(n + 1, unordered_set<int>());

        for (int i = 0; i < n; i++) {
            freq[nums[i]] += 1;
            if (freq[nums[i]] > 1) {
                buckets[freq[nums[i]] - 1].erase(nums[i]);
            }
            buckets[freq[nums[i]]].insert(nums[i]);
        }

        vector<int> topK;
        for (int i = n; i > 0; i--) {
            unordered_set<int> numbers = buckets[i];

            int size = numbers.size();
            k = k - size;

            for (int number : numbers) {
                topK.push_back(number);
            }

            if (k == 0) {
                break;
            }
        }

        return topK;
    }
};
