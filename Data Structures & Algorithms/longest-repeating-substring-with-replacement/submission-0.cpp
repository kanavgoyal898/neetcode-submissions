class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int maxFreq = 0;
        unordered_map<char, int> freq;

        int i = 0;
        int j = 0;

        int maxLength = 0;
        while (i < n && j < n) {
            freq[s[j]] += 1;
            maxFreq = max(maxFreq, freq[s[j]]);

            while (j - i + 1 - maxFreq > k) {
                freq[s[i]] -= 1;
                if (freq[s[i]] == 0) {
                    freq.erase(s[i]);
                }
                i += 1;
            }
            
            maxLength = max(maxLength, j - i + 1);
            j += 1;
        }

        return maxLength;
    }
};
