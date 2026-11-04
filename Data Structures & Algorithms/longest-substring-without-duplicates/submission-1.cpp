class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> stoi;

        int i = 0;
        int j = 0;

        int maxLength = 0;
        while (i < n && j < n) {
            if (stoi.find(s[j]) != stoi.end()) {
                i = max(i, stoi[s[j]] + 1);
            }
            stoi[s[j]] = j;

            int length = j - i + 1;
            maxLength = max(maxLength, length);
            j++;
        }

        return maxLength;
    }
};
