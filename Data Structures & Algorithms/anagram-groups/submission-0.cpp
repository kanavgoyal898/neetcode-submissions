class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> f;
        for (string str : strs) {
            int m = str.length();

            vector<int> f_(26, 0);
            for (int i = 0; i < m; i++) {
                f_[str[i] - 'a'] += 1;
            }

            string h = "_";
            for (int i = 0; i < 26; i++) {
                h += to_string(f_[i]) + "_";
            }

            if (f.find(h) != f.end()) {
                f[h].push_back(str);
            } else {
                f[h] = vector<string>(1, str);
            }
        }

        vector<vector<string>> strs__;
        for (pair<string, vector<string>> kv : f) {
            string h = kv.first;
            vector<string> strs_ = kv.second;
            strs__.push_back(strs_);
        }

        return strs__;
    }
};
