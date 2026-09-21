class Solution {
public:
    bool isAnagram(string s, string t) {
        // Time Complexity: O(n log n)
        // Space Complexity: O(1)

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int s_ = s.length();
        int t_ = t.length();

        if (s_ != t_) {
            return false;
        } else {
            for (int i = 0; i < min(s_, t_); i++) {
                if (s[i] != t[i]) {
                    return false;
                }
            }
            return true;
        }
    }
};
