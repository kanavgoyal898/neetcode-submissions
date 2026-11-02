class Solution {
private:
    struct Comparator {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 0;
            }
            freq[nums[i]] += 1;
        }

        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, Comparator> pq;
        for (pair<int, int> f : freq) {
            pq.push(f);
        }

        vector<int> topK;
        while (k--) {
            pair<int, int> t = pq.top();
            pq.pop();

            int num = t.first;
            int freq = t.second;
            topK.push_back(num);
        }

        return topK;
    }
};
