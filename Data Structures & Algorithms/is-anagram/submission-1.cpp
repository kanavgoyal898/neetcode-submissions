class Solution {
public:
    bool isAnagram(string s, string t) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)

        int s_ = s.length();
        int t_ = t.length();

        if (s_ != t_) {
            return false;
        } else {
            unordered_map<int, int> f;

            for (int i = 0; i < min(s_, t_); i++) {
                if (f.find(s[i]) == f.end()) {
                    f[s[i]] = 0;
                }
                f[s[i]] += 1;

                if (f.find(t[i]) == f.end()) {
                    f[t[i]] = 0;
                }
                f[t[i]] -= 1;
            }

            for (pair<int, int> kv: f) {
                int k = kv.first;
                int v = kv.second;

                if (v != 0) {
                    return false;
                }
            }

            return true;
        }
    }
};
