class Solution {
private:
    bool checkPermutation(vector<int> freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();

        vector<int> freq(26, 0);
        for (int i = 0; i < m; i++) {
            freq[s1[i] - 'a'] += 1;
        }

        int n = s2.length();

        for (int i = 0; i < n; i++) {
            freq[s2[i] - 'a'] -= 1;
            if (i >= m) {
                freq[s2[i - m] - 'a'] += 1;
            }

            if (checkPermutation(freq)) {
                return true;
            }
        }

        return false;
    }
};
