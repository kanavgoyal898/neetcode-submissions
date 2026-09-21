class Solution {
private:
    string hash(string& s) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a'] += 1;
        }

        string h = " ";
        for (int i = 0; i < 26; i++) {
            h += to_string(freq[i]) + " ";
        }

        return h;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Time Complexity: O(m * n)
        // Space Complexity: O(m)

        int m = strs.size();

        int groupCount = 0;
        vector<vector<string>> groups;
        unordered_map<string, int> groupMap;
        for (int i = 0; i < m; i++) {
            string h = hash(strs[i]);
            if (groupMap.find(h) != groupMap.end()) {
                groups[groupMap[h]].push_back(strs[i]);
            } else {
                groups.push_back({strs[i]});
                groupMap[h] = groupCount;
                groupCount += 1;
            }
        }

        return groups;
    }
};
