class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m != n) {
            return false;
        } else {
            vector<int> s_f(26, 0);
            vector<int> t_f(26, 0);

            for (int i = 0; i < max(m, n); i++) {
                s_f[s[i] - 'a'] += 1;
                t_f[t[i] - 'a'] += 1;
            }

            for (int i = 0; i < 26; i++) {
                if (s_f[i] != t_f[i]) {
                    return false;
                }
            }

            return true;
        }
    }
};
