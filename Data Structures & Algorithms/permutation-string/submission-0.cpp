class Solution {
private:
    bool checkPermutation(vector<int> freq1, vector<int> freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();

        vector<int> freq1(26, 0);
        for (int i = 0; i < m; i++) {
            freq1[s1[i] - 'a'] += 1;
        }

        int n = s2.length();

        vector<int> freq2(26, 0);
        for (int i = 0; i < n; i++) {
            freq2[s2[i] - 'a'] += 1;
            if (i >= m) {
                freq2[s2[i - m] - 'a'] -= 1;
            }

            if (checkPermutation(freq1, freq2)) {
                return true;
            }
        }

        return false;
    }
};
